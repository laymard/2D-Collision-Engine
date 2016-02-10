#pragma once
#include <math.h>
#include <vector>
#include "Vector3.h"

class Entity
{
public:
	Entity();
	~Entity();

	Entity(Vector3* pos, float range) :_position(pos), _aggroRange(range), _entitiesInRange(0){}
	Entity(float x, float y, float z, float range);

	void Entity::isInRange(Entity*);
	Vector3& getPos();
	int getEntitiesInRange();

private:
	Vector3* _position;
	float _aggroRange;
	int _entitiesInRange;
};

