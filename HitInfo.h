#pragma once
#include"Vector.h"

class HitInfo
{
public:
	HitInfo(bool isHit, Vector position, Vector normal)
		: isHit(isHit), position(position), normal(normal) {}

	bool isHit;
	Vector position;
	Vector normal;
};