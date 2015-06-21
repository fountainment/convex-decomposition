#include <cstdio>
#include <vector>
#include <queue>
#include "vec2.h"
#include "vec3.h"

using namespace std;
using namespace fim;

typedef vector<vec2> Polygon;
typedef vector<vec2> PointList;
typedef vector<vec2> VecList;
typedef vector<int> IndexList;
typedef vector<Polygon> PolygonList;
typedef queue<Polygon> PolygonQueue;

int getConcavePoint(const Polygon & ori)
{
	int ans = -1;
	int size = (int)ori.size();
	for (int i = 0; i < size; i++) {
		int prev = ((i - 1) % size + size) % size;
		int next = ((i + 1) % size + size) % size;

		vec2 prevPoint = ori[prev];
		vec2 curPoint = ori[i];
		vec2 nextPoint = ori[next];

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

IndexList getVisiblePointIndex(const Polygon & ori, int ccPoint)
{
	IndexList res;
	//TODO:
	return res;
}

PolygonList cutPolygon(const Polygon & ori, int ccPoint)
{
	PolygonList res;
	IndexList iList = getVisiblePointIndex(ori, ccPoint);	
	if (iList.size()) {
		//TODO:
	} else {
		//TODO:
	}
	return res;
}

PolygonList convexDecomposition(const Polygon & ori)
{
	PolygonList res;
	PolygonQueue processQueue;
	processQueue.push(ori);
	while(!processQueue.empty()) {
		Polygon tmp = processQueue.front();
		processQueue.pop();
		int ccPoint = getConcavePoint(tmp);
		if (ccPoint == -1) {
			res.push_back(tmp);
		} else {
			PolygonList twoPolygon = cutPolygon(tmp, ccPoint);
			for (int i = 0; i < (int)twoPolygon.size(); i++) {
				processQueue.push(twoPolygon[i]);
			}
		}
	}
	return res;
}

int main()
{
	Polygon ori;
	ori.push_back(vec2(0.0, 0.0));
	ori.push_back(vec2(2.0, 0.0));
	ori.push_back(vec2(2.0, 2.0));
	ori.push_back(vec2(1.0, 1.0));
	ori.push_back(vec2(0.0, 2.0));
	PolygonList ans = convexDecomposition(ori);
	for (int i = 0; i < (int)ans.size(); i++) {
		Polygon tmp = ans[i];
		for (int j = 0; j < (int)tmp.size(); j++) {
			printf("%f %f\n", tmp[j].getX(), tmp[j].getY());
		}
		printf("\n");
	}
	return 0;
}

