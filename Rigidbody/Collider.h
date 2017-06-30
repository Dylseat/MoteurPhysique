#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Rigidbody.h"

class Collision
{
public:
	Collision(float x, float y);
	~Collision();

	virtual bool isColliding(Collision*) = 0;
	float GetX();
	float GetY();
	Rigidbody rigidbody;
	virtual void Update();

	void TestCollision(Collision* otherCollision);

protected:
	float x;
	float y;

};

class Circle;

class Rectangle : public Collision
{
public:
	Rectangle(float width, float height, float x, float y);
	~Rectangle();

	void Update();

	bool Rectangle::isColliding(Collision*);
	bool Rectangle::isColliding(Rectangle*);
	bool Rectangle::isColliding(Circle*);

	float GetWidth();
	float GetHeight();

	sf::RectangleShape rectangle;

private:
	float width;
	float height;
};


class Circle : public Collision
{
public:
	Circle(float r, float x, float y);
	~Circle();

	void Update();

	bool Circle::isColliding(Collision*);
	bool Circle::isColliding(Rectangle*);
	bool Circle::isColliding(Circle*);

	float r;

	sf::CircleShape circle;
};

#endif // !COLLIDER_H
