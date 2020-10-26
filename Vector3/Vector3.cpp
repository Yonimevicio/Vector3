#include "Vector3.h"

template <class Tp>
// Constructors
Vector3<Tp>::Vector3()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

template <class Tp>
Vector3<Tp>::Vector3(const Tp x, const Tp y, const Tp z)
{
	x = x;
	y = y;
	z = z;
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
Vector3<Tp>& Vector3<Tp>::operator += (Tp v)
{
	x += v;
	y += v;
	z += v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator -= (Tp v)
{
	x -= v;
	y -= v;
	z -= v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator *= (Tp v)
{
	x *= v;
	y *= v;
	z *= v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator /= (Tp v)
{
	x /= v;
	y /= v;
	z /= v;
	return *this;
}

//vector op

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator += (const Vector3<Tp>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
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
	if (n) { //epsilon
		x /= n;
		y /= n;
		z /= n;
	}
	return *this;
}


template <class Tp>
inline const Vector3<Tp> Vector3<Tp>::cross_product(const Vector3<Tp>& v) const
{
	return vector3<Tp>(
		(x * v.z) - (z * v.y),
		(z * v.x) - (x * v.z),
		(x * v.y) - (y * v.x)
		);
}

