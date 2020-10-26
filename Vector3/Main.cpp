#include <iostream>
#include "Vector3.h"
using namespace std;
int main()
{
    Vector3<float> vec1{1.0,0.0,1.0};
    Vector3<float> vec2(vec1);

    Vector3<float> vec3 = vec1 + vec2;
    Vector3<float> vec4 = vec1 - vec2;

    std::cout << "Dot product d dot b: " << vec3.dot_product(vec1) << std::endl;
    std::cout << "Distance between d & b: " << vec3.distance_to(vec1) << std::endl;
    std::cout << "Angle between d & b: " << vec3.angle_between(vec1) << std::endl;
}
