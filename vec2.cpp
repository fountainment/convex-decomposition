#include "vec2.h"
#include <cmath>

fim::vec2::vec2()
:x(0),
 y(0)
{
}

fim::vec2::vec2(double xy)
:x(xy),
 y(xy)
{
}

fim::vec2::vec2(double tx, double ty)
:x(tx),
 y(ty)
{
}

void fim::vec2::move(double tx, double ty)
{
	x += tx;
	y += ty;
}

void fim::vec2::move(const vec2 & vec)
{
	move(vec.x, vec.y);
}

const fim::vec2 fim::vec2::operator+(const vec2 & rhs) const
{
	vec2 res(*this);
	res.move(rhs);
	return res;
}

const fim::vec2 fim::vec2::operator-() const
{
	vec2 res(*this);
	res.x *= -1;
	res.y *= -1;
	return res;
}

const fim::vec2 fim::vec2::operator-(const vec2 & rhs) const
{
	vec2 res(*this);
	res.move(-rhs);
	return res;
}

double fim::vec2::length() const
{
	return std::sqrt(x * x + y * y);
}

double fim::vec2::crossProduct(const vec2 & vec) const
{
	double res = x * vec.y - vec.x * y;
	return res;
}
