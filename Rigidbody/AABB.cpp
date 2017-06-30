#include "AABB.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
AABB::AABB(Vector2 c, Vector2 s)
{
	center = c;
	size = s;
}

AABB::AABB()
{
	center = Vector2(0.0f, 0.0f);
	size = Vector2(0.0f, 0.0f);
}

void AABB::SetCenter(Vector2 c)
{
	center = c;
	
}

void AABB::SetSize(Vector2 s)
{
	size = s;

}

void AABB::setCenter(Vector2 p)
{
	center = p;
}

bool AABB::IsOverlapping(AABB* aabb)
{
	if ((this->center.x + this->size.x) < aabb->center.x || this->center.x > (aabb->center.x + aabb->size.x))
	{
		return false;
	}
	if ((this->center.y + this->size.y) < aabb->center.y || (aabb->center.y + aabb->size.y) < this->center.y)
	{
		return false;
	}
	else
	{
		return true;
	}

}

AABB::~AABB()
{

}