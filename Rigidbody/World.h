#ifndef WORLD_H
#define WORLD_H
#include <list>
#include "Rigidbody.h"
#include "AABB.h"

class World
{

private:

	std::list <Rigidbody*> bodies;
	AABB aabb;

public:

	World();
	Rigidbody* addBodyWorld();
	~World();
};

#endif // !World