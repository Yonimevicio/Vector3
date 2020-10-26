#pragma once
#include <cmath>
#include <limits>
template<class Tp>
class Vector3 
{
public:
	Tp x,y,z;
	Vector3();
	Vector3(const Tp x, const Tp y, const Tp z);
	Vector3(const Vector3<Tp>& v);

	//math op
	const Tp magnitude() const;
	Vector3<Tp>& normalize();
	const Tp dot_product(const Vector3<Tp>&) const;
	const Vector3<Tp> cross_product(const Vector3<Tp>&) const;
	const float distance_to(const Vector3<Tp>&) const;
	const float angle_between(const Vector3<Tp>&) const;
	const float round_epsilon(const float number) const;
	
	//scalar op             
	Vector3<Tp>& operator*(const Tp s);
	Vector3<Tp>& operator/(const Tp s);

	//vector op
	Vector3<Tp>& operator+(const Vector3<Tp>& v); 
	Vector3<Tp>& operator-(const Vector3<Tp>& v);

};

template <class Tp>
// Constructors
Vector3<Tp>::Vector3()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

template <class Tp>
Vector3<Tp>::Vector3(const Tp _x, const Tp _y, const Tp _z)
{
	x = _x;
	y = _y;
	z = _z;
}

template <class Tp>
Vector3<Tp>::Vector3(const Vector3<Tp>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

//scalar op

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator * (Tp v)
{
	x *= v;
	y *= v;
	z *= v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator / (Tp v)
{
	x /= v;
	y /= v;
	z /= v;
	return *this;
}

//vector op

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator + (const Vector3<Tp>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator - (const Vector3<Tp>& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

//math op

template <class Tp>
inline const Tp Vector3<Tp>::dot_product(const Vector3<Tp>& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

template <class Tp>
inline const Tp Vector3<Tp>::magnitude() const
{
	return (Tp)sqrt(dot_product(*this));
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::normalize()
{
	Tp n = magnitude();
	float ep = round_epsilon(n);
	if(ep) { //epsilon
		x /= ep;
		y /= ep;
		z /= ep;
	}
	return *this;
}

template <class Tp>
inline const Vector3<Tp> Vector3<Tp>::cross_product(const Vector3<Tp>& v) const
{
	return Vector3<Tp>(
		(x * v.z) - (z * v.y),
		(z * v.x) - (x * v.z),
		(x * v.y) - (y * v.x)
		);
}

template<class Tp>
inline const float Vector3<Tp>::round_epsilon(const float number) const
{
	float eps = std::numeric_limits<float>::epsilon();
	float n2 = number;
	if (number <  eps && number > -eps) n2 = 0.0;

	return n2;
}

template <class Tp>
inline const float Vector3<Tp>::distance_to(const Vector3<Tp>& vec) const
{
	Tp opx = x - vec.x;
	Tp opy = x - vec.y;
	Tp opz = x - vec.z;
	return sqrt(
		(opx) * (opx) +
		(opy) * (opy) +
		(opz) * (opz));
}

template<class Tp>
inline const float Vector3<Tp>::angle_between(const Vector3<Tp>& vec) const
{	
	float dot = dot_product(vec);
	dot = dot / (magnitude() * vec.magnitude());
	dot = (dot < -1.0 ? -1.0 : (dot > 1.0 ? 1.0 : dot));
	return acos(dot);
}