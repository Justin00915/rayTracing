#pragma once
#include"Vector.h"

class Ray
{
public:
	Ray(Vector position, Vector direction)
		: position(position), direction(direction) {}

	Vector position;
	Vector direction;
};