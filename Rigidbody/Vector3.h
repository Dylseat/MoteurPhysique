#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H
class Vector3
{

public:
	Vector3(float x, float y, float z);

	float x;
	float y;
	float z;

	Vector3 operator+(Vector3 vector1);
	Vector3 operator-(Vector3 vector1);
	Vector3 operator*(float m);

	void Show();
	float Length();
	static float Dot(Vector3 vector1, Vector3 vector2);

	static Vector3 Cross(Vector3 vector1, Vector3 vector2);
	static Vector3 Lerp(Vector3 vector1, Vector3 vector2, float ratio);
	static Vector3 Proj(Vector3 vector1, Vector3 vector2);
	static Vector3 Refl(Vector3 inDir, Vector3 normal);
	static float AnglesBetween(Vector3 vector1, Vector3 vector2);

	~Vector3();
};
#endif // !VECTOR3_H