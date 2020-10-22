#pragma once
#include <cmath>
template<class Tp>
class Vector3 
{
public:
	Vector3();
	Vector3(const Tp x, const Tp y, const Tp z);
	Vector3(const Vector3<Tp>& v);

	//math op
	Vector3<Tp>& normalize();
	const float distance_to(const Vector3<Tp>&) const;
	const Tp dot_product(const Vector3<Tp>&) const;
	const Vector3<T> cross_product(const Vector3<T>&) const;
	const float angle_between(const Vector3<Tp>&) const;
	
	//scalar op
	Vector3<Tp>& operator+=(const Tp s);                  
	Vector3<Tp>& operator-=(const Tp s);                  
	Vector3<Tp>& operator*=(const Tp s);
	Vector3<Tp>& operator/=(const Tp s);

	//vector op
	Vector3<Tp>& operator+=(const Vector3<Tp>& v);
	/*Vector3<Tp>& operator-=(const vector3<Tp>& v);        
	Vector3<Tp>& operator*=(const vector3<Tp>& v);*/        
private:
	const Tp norm() const;
	Tp vec3[3];
};