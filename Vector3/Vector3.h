#pragma once
#include <cmath>
template<class Tp>
class Vector3 
{
public:
	Vector3();
	Vector3(const Tp x, const Tp y, const Tp z);
	Vector3(const Vector3<Tp>& v);

	Vector3<Tp>& normalize();
	const Tp distance_to(const Vector3<Tp>&) const;
	const Tp dot_product(const Vector3<Tp>&) const;
	const Vector3<T> cross_product(const Vector3<T>&) const;
	const Tp angle_between(const Vector3<Tp>&) const;
	
	//scalar op
	Vector3<Tp>& operator+=(const Tp s);                  
	Vector3<Tp>& operator-=(const Tp s);                  
	Vector3<Tp>& operator*=(const Tp s);

	//vector op
	Vector3<Tp>& operator+=(const vector3<Tp>& v);        
	Vector3<Tp>& operator-=(const vector3<Tp>& v);        
	Vector3<Tp>& operator*=(const vector3<Tp>& v);        
private:
	Tp vec3[3];
};