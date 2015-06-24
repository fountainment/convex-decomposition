#include "polygon.h"
#include <algorithm>

fim::PolygonList fim::Polygon::convexDecomposition()
{
	fim::PolygonList res;
	fim::PolygonQueue processQueue;
	processQueue.push(*this);
	while(!processQueue.empty()) {
		auto tmp = processQueue.front();
		processQueue.pop();
		int ccPoint = tmp.getConcavePoint();
		if (ccPoint == -1 && tmp.size() >= 3) {
			res.push_back(tmp);
		} else {
			auto twoPolygon = tmp.cutPolygon(ccPoint);
			for (int i = 0; i < (int)twoPolygon.size(); i++) {
				processQueue.push(twoPolygon[i]);
			}
		}
		if (res.size() > 100 || processQueue.size() > 100) {
			break;
		}
	}
	return res;
}

int fim::Polygon::indexNormalize(int index)
{
	int sz = (int)size();
	return (index % sz + sz) % sz;
}

int fim::Polygon::insertPoint(const vec2 & p)
{
	int ans = 0;
	fim::vec2 lastVec;
	fim::segment seg;
	for (Polygon::iterator it = begin(); it != end(); ++it) {
		if (it != begin()) {
			seg = fim::segment(lastVec, *it);
			if (seg.collidePoint(p)) {
				ans = std::distance(begin(), insert(it, p));
				break;
			}
		}
		lastVec = *it;
	}
	if (ans == 0) insert(begin(), p);
	return ans;
}

const fim::vec2 fim::Polygon::getPoint(int index)
{
	index = indexNormalize(index);
	return (*this)[index];
}

const fim::vec2 fim::Polygon::getVector(int index)
{
	return getPoint(index + 1) - getPoint(index);
}

const fim::segment fim::Polygon::getSegment(int index)
{
	return fim::segment(getPoint(index), getPoint(index + 1));
}

bool fim::Polygon::isConcavePoint(int index)
{
	auto prev = getVector(index - 1);
	auto cur = getVector(index);
	double cp = prev.crossProduct(cur);
	if (cp < 0) return true;
	else return false;
}

int fim::Polygon::getConcavePoint()
{
	int ans = -1;
	int sz = (int)size();
	for (int i = 0; i < sz; i++) {
		if (isConcavePoint(i)) {
			ans = i;
			break;
		}
	}
	return ans;
}

static fim::vec2 raySrc;
bool cmpDistanceToSrc(const fim::vec2 & a, const fim::vec2 & b)
{
	return (a - raySrc).length() < (b - raySrc).length();
}

fim::Point2List fim::Polygon::collideRay(const fim::vec2 & src, const fim::vec2 & drct)
{
	fim::Point2List res;
	fim::Point2List uniqueRes;
	for (int i = 0; i < (int)size(); i++) {
		auto seg = getSegment(i);
		fim::vec2 tmp; 
		if (seg.collideRay(tmp, src, drct)) {
			res.push_back(tmp);
		}
	}
	raySrc = src;
	std::sort(res.begin(), res.end(), cmpDistanceToSrc);
	for (int i = 0; i < (int)res.size(); i++) {
		if (i == 0 || res[i] != res[i - 1]) {
			uniqueRes.push_back(res[i]);
		}
	}
	return uniqueRes;
}

fim::IndexList fim::Polygon::getVisiblePointIndex(int ccPoint)
{
	fim::IndexList res;
	auto left = getSegment(ccPoint);
	auto right = getSegment(ccPoint - 1);
	right.swapAB();
	left.b = left.a - left.getVector();
	right.b = right.a - right.getVector();
	for (int i = 0; i < (int)size(); i++) {
		if (i == ccPoint) continue;
		auto p = getPoint(i);
		if (left.leftOrRight(p) == 1
			&& right.leftOrRight(p) == -1) {
			auto pl = collideRay(getPoint(ccPoint), p - getPoint(ccPoint));
			if (pl.size() == 0 || pl[0] == p)
			{
				res.push_back(i);
			}
		}
	}
	return res;
}

fim::PolygonList fim::Polygon::cutPolygon(int ccPoint, int anoPoint)
{
	fim::PolygonList res;
	fim::Polygon tmp;
	int cur = anoPoint;
	tmp.push_back(getPoint(ccPoint));
	tmp.push_back(getPoint(anoPoint));
	cur = indexNormalize(cur + 1);
	while (cur != ccPoint) {
		tmp.push_back(getPoint(cur));
		cur = indexNormalize(cur + 1);
	}
	res.push_back(tmp);
	tmp.clear();
	cur = ccPoint;
	tmp.push_back(getPoint(anoPoint));
	tmp.push_back(getPoint(ccPoint));
	cur = indexNormalize(cur + 1);
	while (cur != anoPoint) {
		tmp.push_back(getPoint(cur));
		cur = indexNormalize(cur + 1);
	}
	res.push_back(tmp);
	return res;
}

fim::PolygonList fim::Polygon::cutPolygon(int ccPoint)
{
	fim::PolygonList res;
	auto iList = getVisiblePointIndex(ccPoint);	
	if (!iList.empty()) {
		return cutPolygon(ccPoint, iList[0]);
	} else {
		auto left = -getVector(ccPoint);
		auto right = getVector(ccPoint - 1);
		auto middleVec = (left.normalize() + right.normalize()) / 2.0; 
		auto pl = collideRay(getPoint(ccPoint), middleVec);
		if (!pl.empty()) {
			int loc = insertPoint(pl[0]);
			if (loc <= ccPoint) {
				ccPoint = indexNormalize(ccPoint + 1);
			}
			return cutPolygon(ccPoint, loc);
		} else {
			//TODO: debug output
		}
	}
	return res;
}

