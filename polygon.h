#ifndef _FIM_POLYGON_H_
#define _FIM_POLYGON_H_

#include "vec2.h"
#include <vector>
#include <queue>

namespace fim {

typedef std::vector<vec2> Point2List;
typedef std::vector<int> IndexList;

class Polygon : public Point2List
{
public:
	std::vector<Polygon> convexDecomposition();
protected:
	int getConcavePoint();	
	IndexList getVisiblePointIndex(int ccPoint);
	std::vector<Polygon> cutPolygon(int ccPoint);
};

typedef std::vector<Polygon> PolygonList;
typedef std::queue<Polygon> PolygonQueue;

}

#endif
