#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H
#include "Vector3.h"
class Vector2
{
public:
	Vector2(float x, float y);
	Vector2();

	float x;
	float y;
	
	Vector2 operator+(Vector2 vector1);
	Vector2 operator-(Vector2 vector1);
	Vector2 operator*(float m);

	void Show();
	float Length();
	static float Dot(Vector2 vector1, Vector2 vector2);

	static Vector3 Cross(Vector2 vector1, Vector2 vector2);
	static Vector2 Lerp(Vector2 vector1, Vector2 vector2, float ratio);
	static Vector2 Proj(Vector2 vector1, Vector2 vector2);
	static Vector2 Refl(Vector2 inDir, Vector2 normal);
	static float AnglesBetween(Vector2 vector1, Vector2 vector2);
	

	~Vector2();
};
#endif // !VECTOR2_H