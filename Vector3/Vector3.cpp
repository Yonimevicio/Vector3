#include "Vector3.h"

template <class Tp>
// Constructors
Vector3<Tp>::Vector3()
{
	vec3[0] = 0.0;
	vec3[1] = 0.0;
	vec3[2] = 0.0;
}

template <class Tp>
Vector3<Tp>::Vector3(const Tp x, const Tp y, const Tp z)
{
	vec3[0] = x;
	vec3[1] = y;
	vec3[2] = z;
}

template <class Tp>
Vector3<Tp>::Vector3(const Vector3<Tp>& v)
{
	vec3[0] = v[0];
	vec3[1] = v[1];
	vec3[2] = v[2];
}

//scalar op

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator += (Tp v)
{
	vec3[0] += v;
	vec3[1] += v;
	vec3[2] += v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator -= (Tp v)
{
	vec3[0] -= v;
	vec3[1] -= v;
	vec3[2] -= v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator *= (Tp v)
{
	vec3[0] *= v;
	vec3[1] *= v;
	vec3[2] *= v;
	return *this;
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator /= (Tp v)
{
	vec3[0] /= v;
	vec3[1] /= v;
	vec3[2] /= v;
	return *this;
}



//vector op

template <class Tp>
Vector3<Tp>& Vector3<Tp>::operator += (const Vector3<Tp>& v)
{
	vec3[0] += vec3[0];
	vec3[1] += vec3[1];
	vec3[2] += vec3[2];
	return *this;
}

//math op
template <class Tp>
inline const Tp Vector3<Tp>::dot_product(const Vector3<Tp>& v) const
{
	return vec3[0] * v[0] + vec3[1] * v[1] + vec3[2] * v[2];
}

template <class Tp>
inline const Tp Vector3<Tp>::norm() const
{
	return (Tp)sqrt(dot_product(*this));
}

template <class Tp>
Vector3<Tp>& Vector3<Tp>::normalize()
{
	Tp n = norm();
	if (n) {
		vec3[0] /= n;
		vec3[1] /= n;
		vec3[2] /= n;
	}
	return *this;
}


