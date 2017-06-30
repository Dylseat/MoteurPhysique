#include "Vector2.h"
#include "iostream"
#include "Vector3.h"

Vector2::Vector2(float vx, float vy)
{
	x = vx;
	y = vy;
}

Vector2::Vector2()
{

}

Vector2 Vector2::operator+(Vector2 vector1)
{
	Vector2 Vector(0.0f, 0.0f);
	Vector.x = vector1.x + x;
	Vector.y = vector1.y + y;

	return Vector;
}

Vector2 Vector2::operator-(Vector2 vector1)
{
	Vector2 Vector(0.0f, 0.0f);
	Vector.x = vector1.x - x;
	Vector.y = vector1.y - y;

	return Vector;
}

Vector2 Vector2::operator*(float m)
{
	Vector2 Vector(0.0f, 0.0f);
	Vector.x = m * x;
	Vector.y = m * y;

	return Vector;
}

float Vector2::Length()
{
	return sqrt(x*x + y*y);
}

float Vector2::Dot(Vector2 vector1, Vector2 vector2)
{
	return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

Vector3 Vector2::Cross(Vector2 vector1, Vector2 vector2)
{
	Vector3 Vector(0.0f, 0.0f, 0.0f);
	Vector.z = (vector1.x * vector2.y - vector1.y * vector2.x);

	return Vector;
}

Vector2 Vector2::Lerp(Vector2 vector1, Vector2 vector2, float ratio)
{
	return vector1 + ((vector2 - vector1) * ratio);
}

Vector2 Vector2::Proj(Vector2 vector1, Vector2 vector2)
{
	return vector1 * (Vector2::Dot(vector2, vector1) / Vector2::Dot(vector1, vector2));
}

Vector2 Vector2::Refl(Vector2 inDir, Vector2 normal)
{
	return  inDir - normal * (2 * Vector2::Dot(inDir, normal));
}

float Vector2::AnglesBetween(Vector2 vector1, Vector2 vector2)
{
	return acos(Vector2::Dot(vector1, vector2) /
		(vector1.Length() * vector2.Length()));
}

void Vector2::Show()
{
	std::cout << "x: " << x << "y: " << y << "\n";
}

Vector2::~Vector2()
{

}