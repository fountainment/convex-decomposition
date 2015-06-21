#ifndef FIM_VEC2
#define FIM_VEC2

namespace fim {

class vec2
{
public:
	vec2();
	vec2(double tx, double ty);
	void move(double tx, double ty);
	void move(const vec2 & vec);

	double getX() const;
	double getY() const;
	void setX(double tx);
	void setY(double ty);

	const vec2 operator+(const vec2 & rhs) const;
	const vec2 operator-() const;
	const vec2 operator-(const vec2 & rhs) const;

	double crossProduct(const vec2 & vec) const;
protected:
	double x, y;
};

}

#endif
