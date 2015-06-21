#include "segment.h"

fim::segment::segment()
{
}

fim::segment::segment(vec2 pa, vec2 pb)
:a(pa),
 b(pb)
{
}

double fim::segment::length() const
{
	return (b - a).length();
}

bool fim::segment::rectCollidePoint(const fim::vec2 & p) const
{
	return ((p.x - a.x) * (p.x - b.x) <= 0
		&& (p.y - a.y) * (p.y - b.y) <= 0);
}

bool fim::segment::collidePoint(const fim::vec2 & p) const
{
	return ((p - a).crossProduct(b - a) == 0 && rectCollidePoint(p));
}

bool fim::segment::collideSegment(vec2 & pt, const segment & seg) const
{
	fim::vec2 pa(a), pb(b), pc(seg.a), pd(seg.b), intersection;
	intersection.x = ((pb.x - pa.x) * (pc.x - pd.x) * (pc.y - pa.y) -
	pc.x * (pb.x - pa.x) * (pc.y - pd.y) + pa.x * (pb.y - pa.y) * (pc.x - pd.x)) /
	((pb.y - pa.y) * (pc.x - pd.x) - (pb.x - pa.x) * (pc.y - pd.y));
	intersection.y = ((pb.y - pa.y) * (pc.y - pd.y) * (pc.x - pa.x) - pc.y
	* (pb.y - pa.y) * (pc.x - pd.x) + pa.y * (pb.x - pa.x) * (pc.y - pd.y))
	/ ((pb.x - pa.x) * (pc.y - pd.y) - (pb.y - pa.y) * (pc.x - pd.x));
	if (rectCollidePoint(intersection) && seg.rectCollidePoint(intersection)) {
		pt = intersection;
		return true;
	} else {
		return false;
	}
}
