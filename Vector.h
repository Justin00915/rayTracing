#pragma once
#include<math.h>

class Vector
{
public:
	double x;
	double y;
	double z;

	Vector(double x = 0, double y = 0, double z = 0)
		: x(x), y(y), z(z) { }

	double GetLength() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	Vector GetNormalized()
	{
		double l = GetLength();
		if (l == 0)
		{
			return *this;
		}
		return Vector(x / l, y / l, z / l);
	}

	void Normalize()
	{
		double l = GetLength();
		x /= l;
		y /= l;
		z /= l;
	}

	Vector GetAbsolutized()
	{
		return Vector(fabs(x), fabs(y), fabs(z));
	}

	void Absolutize()
	{
		x = fabs(x);
		y = fabs(y);
		z = fabs(z);
	}

	double Dot(Vector other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	double GetDist(Vector other)
	{
		return (*this - other).GetLength();
	}

	double GetMax() const
	{
		return fmax(fmax(x, y), z);
	}

	double GetAbsMax() const
	{
		return fmax(fmax(fabs(x), fabs(y)), fabs(z));
	}

	double GetMin() const
	{
		return fmin(fmin(x, y), z);
	}

	double GetAbsMin() const
	{
		return fmin(fmin(fabs(x), fabs(y)), fabs(z));
	}

	//Component-wise
	Vector operator+(Vector other)
	{
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	//Component-wise
	Vector operator+=(Vector other)
	{
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	//Component-wise
	Vector operator-(Vector other)
	{
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	//Component-wise
	Vector operator-=(Vector other)
	{
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	//Component-wise
	Vector operator*(Vector other)
	{
		return Vector(x * other.x, y * other.y, z * other.z);
	}

	//Component-wise
	Vector operator*=(Vector other)
	{
		return Vector(x * other.x, y * other.y, z * other.z);
	}

	//Component-wise
	Vector operator/(Vector other)
	{
		return Vector(x / other.x, y / other.y, z / other.z);
	}

	//Component-wise
	Vector operator/=(Vector other)
	{
		return Vector(x / other.x, y / other.y, z / other.z);
	}

	Vector operator*(double lambda)
	{
		return Vector(x * lambda, y * lambda, z * lambda);
	}

	Vector operator*=(double lambda)
	{
		return Vector(x * lambda, y * lambda, z * lambda);
	}

	Vector operator/(double lambda)
	{
		return Vector(x / lambda, y / lambda, z / lambda);
	}

	Vector operator/=(double lambda)
	{
		return Vector(x / lambda, y / lambda, z / lambda);
	}

	//Component-wise
	bool operator==(Vector other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
};