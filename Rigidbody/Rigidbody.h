#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2.h"
#include "AABB.h"
class Rigidbody
{

private:
	AABB aabb;
	Vector2 force;
	Vector2 delta;
	Vector2 acceleration;
	Vector2 position;
	Vector2 speed;
	float mass;


public:
	Rigidbody();
	Vector2 Addforce(Vector2 acceleration);
	Vector2 SetAcceleration();
	Vector2 GetPosition();
	void Update();
	void SetMass(float newMass);
	void SetPos(Vector2 newP);
	void SetSpeed(Vector2 newSpeed);


	~Rigidbody();
};
#endif // !RIGIDBODY_H