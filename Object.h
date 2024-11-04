#pragma once
#include"vector.h"

class Object
{
public:
	Object(Vector position)
		: position(position) {};

	Vector position;
};