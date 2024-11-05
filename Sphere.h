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
		Vector closestRayPointPos = ray.position * 2 + position / (ray.position.Dot(ray.position));
		
		Vector differenceVector = closestRayPointPos - position;

		//Performing the calculation with each side squared saves a sqrt operation
		if ((differenceVector).Dot(differenceVector) <= r * r)
		{
			return HitInfo(true, closestRayPointPos, differenceVector.GetNormalized());
		}
	}

	double r;
};