#include "World.h"

World::World()
{

}

Rigidbody* World::addBodyWorld()
{
	Rigidbody* body = new Rigidbody();
	bodies.push_back(body);
	return body;
}

World::~World()
{
	for (auto i = bodies.begin(); i != bodies.end(); i++)
	{
		delete *i;
	}
	bodies.clear();
}