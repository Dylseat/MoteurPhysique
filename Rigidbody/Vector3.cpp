#include "Vector3.h"
#include <iostream>

Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

Vector3 Vector3::operator+(Vector3 vector1)
{
	Vector3 vector(0.0f, 0.0f, 0.0f);
	vector.x = vector1.x + x;
	vector.y = vector1.y + y;
	vector.z = vector1.z + z;

	return vector;
}

Vector3 Vector3::operator-(Vector3 vector1)
{
	Vector3 vector(0.0f, 0.0f, 0.0f);
	vector.x = vector1.x - x;
	vector.y = vector1.y - y;
	vector.z = vector1.z - z;

	return vector;
}

Vector3 Vector3::operator*(float f)
{
	Vector3 vector(0.0f, 0.0f, 0.0f);
	vector.x = f * x;
	vector.y = f * y;
	vector.z = f * z;

	return vector;
}

float Vector3::Dot(Vector3 vector1, Vector3 vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

Vector3 Vector3::Cross(Vector3 vector1, Vector3 vector2)
{
	Vector3 vector(0.0f, 0.0f, 0.0f);
	vector.x = (vector1.y * vector2.z - vector1.z * vector2.y);
	vector.y = (vector1.z * vector2.x - vector1.x * vector2.z);
	vector.z = (vector1.x * vector2.y - vector1.y * vector2.x);

	return vector;
}

Vector3 Vector3::Lerp(Vector3 vector1, Vector3 vector2, float ratio)
{
	return vector1 + ((vector2 - vector1) * ratio);
}

Vector3 Vector3::Proj(Vector3 vector1, Vector3 vector2)
{
	return vector1 * (Vector3::Dot(vector2, vector1) / Vector3::Dot(vector1, vector1));
}

Vector3 Vector3::Refl(Vector3 inDir, Vector3 normal)
{
	return inDir - normal * (2 * Vector3::Dot(inDir, normal));
}

float Vector3::Length()
{
	return sqrt(x*x + y*y + z*z);
}

float Vector3::AnglesBetween(Vector3 vector1, Vector3 vector2)
{
	return acos(Vector3::Dot(vector1, vector2) / (vector1.Length()*vector2.Length()));
}

void Vector3::Show()
{
	std::cout << "x: " << x << "  y: " << y << "  z: " << z << "\n";
}

Vector3::~Vector3()
{
}