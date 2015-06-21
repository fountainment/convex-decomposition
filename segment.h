#ifndef _FIM_SEGMENT_H_
#define _FIM_SEGMENT_H_

#include "vec2.h"

namespace fim {

class segment
{
public:
	segment();
	segment(vec2 pa, vec2 pb);
	
	double length() const;
	bool rectCollidePoint(const vec2 & p) const;
	bool collidePoint(const vec2 & p) const;
	bool collideSegment(vec2 & pt, const segment & seg) const;

	vec2 a, b;
};

}

#endif
