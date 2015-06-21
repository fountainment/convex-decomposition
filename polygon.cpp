#include "polygon.h"

fim::PolygonList fim::Polygon::convexDecomposition()
{
	fim::PolygonList res;
	fim::PolygonQueue processQueue;
	processQueue.push(*this);
	while(!processQueue.empty()) {
		Polygon tmp = processQueue.front();
		processQueue.pop();
		int ccPoint = tmp.getConcavePoint();
		if (ccPoint == -1) {
			res.push_back(tmp);
		} else {
			auto twoPolygon = tmp.cutPolygon(ccPoint);
			for (int i = 0; i < (int)twoPolygon.size(); i++) {
				processQueue.push(twoPolygon[i]);
			}
		}
	}
	return res;
}

int fim::Polygon::getConcavePoint()
{
	int ans = -1;
	int sz = (int)size();
	for (int i = 0; i < sz; i++) {
		int prev = ((i - 1) % sz + sz) % sz;
		int next = ((i + 1) % sz + sz) % sz;

		vec2 prevPoint = (*this)[prev];
		vec2 curPoint = (*this)[i];
		vec2 nextPoint = (*this)[next];

		vec2 prevVec = curPoint - prevPoint;
		vec2 nextVec = nextPoint - curPoint;
		double cp = prevVec.crossProduct(nextVec);
		if (cp < 0) {
			ans = i;
			break;
		}
	}
	return ans;
}

fim::IndexList fim::Polygon::getVisiblePointIndex(int ccPoint)
{
	fim::IndexList res;
	//TODO:
	return res;
}

fim::PolygonList fim::Polygon::cutPolygon(int ccPoint)
{
	fim::PolygonList res;
	auto iList = getVisiblePointIndex(ccPoint);	
	if (iList.size()) {
		//TODO:
	} else {
		//TODO:
	}
	return res;
}

