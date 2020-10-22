#include "Vector3.h"

template <class Tp>
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

