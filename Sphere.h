#pragma once
#include"Object.h"
#include"HitInfo.h"
#include"Ray.h"

class Sphere : Object
{
public:
	Sphere(Vector position, double r)
		: Object(position), r(r) {};

	HitInfo Intersect(Ray ray)
	{

	}

	double r;
};