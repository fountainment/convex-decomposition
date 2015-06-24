#ifndef _FIM_POLYGON_H_
#define _FIM_POLYGON_H_

#include "vec2.h"
#include "segment.h"
#include <vector>
#include <queue>

namespace fim {

typedef std::vector<vec2> Point2List;
typedef std::vector<int> IndexList;

class Polygon : public Point2List
{
public:
	Point2List collideRay(const vec2 & src, const vec2 & drct);
	std::vector<Polygon> convexDecomposition();
	const Polygon regular();
protected:
	int indexNormalize(int index);

	int insertPoint(const vec2 & p);

	const vec2 getPoint(int index);
	const vec2 getVector(int index);
	const segment getSegment(int index);

	bool isConcavePoint(int index);
	int getConcavePoint();	

	IndexList getVisiblePointIndex(int ccPoint);

	std::vector<Polygon> cutPolygon(int ccPoint, int anoPoint);
	std::vector<Polygon> cutPolygon(int ccPoint);
};

typedef std::vector<Polygon> PolygonList;
typedef std::queue<Polygon> PolygonQueue;

}

#endif
