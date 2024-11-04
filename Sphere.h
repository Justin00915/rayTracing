#pragma once
#include"Object.h"
class Sphere : Object
{
public:
	Sphere(double x, double y, double z, double r)
		: Object(x, y, z), r(r) {};
	double r;
};