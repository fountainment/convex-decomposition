#include "vec2.h"

fim::vec2::vec2()
:x(0),
 y(0)
{}

fim::vec2::vec2(double tx, double ty)
{
	setX(tx);
	setY(ty);
}

void fim::vec2::move(double tx, double ty)
{
	x += tx;
	y += ty;
}

void fim::vec2::move(const vec2 & vec)
{
	move(vec.getX(), vec.getY());
}

double fim::vec2::getX() const
{
	return x;
}

double fim::vec2::getY() const
{
	return y;
}

void fim::vec2::setX(double tx)
{
	x = tx;
}

void fim::vec2::setY(double ty)
{
	y = ty;
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
	res.setX(-res.getX());
	res.setY(-res.getY());
	return res;
}

const fim::vec2 fim::vec2::operator-(const vec2 & rhs) const
{
	vec2 res(*this);
	res.move(-rhs);
	return res;
}

double fim::vec2::crossProduct(const vec2 & vec) const
{
	double res = getX() * vec.getY() - vec.getX() * getY();
	return res;
}
