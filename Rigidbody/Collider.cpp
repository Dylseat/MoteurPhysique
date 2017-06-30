#include "Collider.h"
#include "Vector2.h"

// COLLISION PARAMETER
Collision::Collision(float posX, float posY)
{
	x = posX;
	y = posY;
}

float Collision::GetX()
{
	return x;
}

float Collision::GetY()
{
	return y;
}

void Collision::Update()
{
}

Collision::~Collision()
{
}

void Collision::TestCollision(Collision* otherCollision)
{
	bool Test = isColliding(otherCollision);
	if (Test)
	{
		otherCollision->rigidbody.Addforce(rigidbody.Getforce());
	}

}

// RECTANGLE DETECT COLLISION 
Rectangle::Rectangle(float width, float height, float x, float y) : Collision(x, y)
{
	this->width = width;
	this->height = height;

	sf::RectangleShape Image(sf::Vector2f(width, height));

	this->rectangle = Image;
	this->rectangle.setPosition(x, y);
}

Rectangle::~Rectangle()
{
}

void Rectangle::Update()
{
	rectangle.setPosition(rigidbody.GetPos().x, rigidbody.GetPos().y);
}

bool Rectangle::isColliding(Collision* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}

bool Rectangle::isColliding(Rectangle* rectForm)
{
	// (This rectangle->position + Lenght) < position (rectangle 2) ou position (This rectangle) > position + lenght (rectangle 2)
	if ((this->rectangle.getPosition.x + this->width) < rectForm->rectangle.getPosition().x ||
		this->rectangle.getPosition().x > (rectForm->rectangle.getPosition().x + rectForm->width))
	{
		return false;
	}

	if ((this->rectangle.getPosition().y + this->height) < rectForm->rectangle.getPosition().y ||
		(rectForm->rectangle.getPosition().y + rectForm->height) < this->rectangle.getPosition().y)
	{
		return false;
	}

	return true;
}

bool Rectangle::isColliding(Circle* circleForm)
{
	return circleForm->isColliding(this);
}

float Rectangle::GetHeight()
{
	return this->height;
}

float Rectangle::GetWidth()
{
	return this->width;
}

// CIRCLE DETECT COLLISION
Circle::Circle(float r, float x, float y) : Collision(x, y)
{
	this->r = r;

	sf::CircleShape
		Image(r);

	this->circle = Image;
	circle.setPosition(x, y);
}

void Circle::Update()
{
	circle.setPosition(rigidbody.GetPos().x, rigidbody.GetPos().y);
}

Circle::~Circle()
{
}

bool Circle::isColliding(Collision* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}

bool Circle::isColliding(Rectangle* rectForm)
{
	float circleDistanceX = abs(this->circle.getPosition().x - rectForm->rectangle.getPosition().x);
	float circleDistanceY = abs(this->circle.getPosition().y - rectForm->rectangle.getPosition().y);

	if (circleDistanceX > (rectForm->GetWidth() / 2.0 + this->r))
	{
		return false;
	}

	if (circleDistanceY > (rectForm->GetHeight() / 2 + this->r))
	{
		return false;
	}
	return true;

	if (circleDistanceX <= (rectForm->GetWidth() / 2))
	{
		return true;
	}

	if (circleDistanceY <= (rectForm->GetHeight() / 2))
	{
		return true;
	}

	double cornerDistance = pow((circleDistanceX - rectForm->GetWidth() / 2.0), 2.0) +
		pow((circleDistanceY - rectForm->GetHeight() / 2.0), 2.0);
}

bool Circle::isColliding(Circle* circleForm)
{
	float tempR = this->r + circleForm->r;
	float tempX = this->circle.getPosition().x - circleForm->circle.getPosition().x;
	float tempY = this->circle.getPosition().y - circleForm->circle.getPosition().y;

	if (tempX < tempR)
	{
		return true;
	}

	if (tempY < tempR)
	{
		return true;
	}

	return false;
}