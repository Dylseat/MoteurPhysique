#ifndef AABB_H
#define AABB_H

#include "Vector2.h"
#include <list>
#include <SFML\Graphics.hpp>

struct AABB
{

	AABB(Vector2 c, Vector2 s);
	AABB();

	Vector2 center;
	Vector2 size;

	void SetCenter(Vector2 c);
	void SetSize(Vector2 s);

	void update(sf::RenderWindow* w);

	sf::RectangleShape rectangle;
	bool IsOverlapping(AABB*);
	void setCenter(Vector2 position);
	~AABB();
};

#endif // !AABB