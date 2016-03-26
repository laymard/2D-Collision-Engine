#pragma once
#include <math.h>
#include <vector>
#include "MyVector3.h"
#include "../../nclgl/Mesh.h"

class Entity
{
public:
	Entity();
	~Entity();

	Entity(MyVector3* pos, float range) :_position(pos), _aggroRange(range), _entitiesInRange(0){}
	Entity(float x, float y, float z, float range);

	void Entity::isInRange(Entity*);

	static Entity* generateTable(float w, float h);
	static Entity* generateBound(float x1, float y1, float x2, float y2, Vector4 colour);


	MyVector3& getPos();
	MyVector3& getVel();
	MyVector3& getAcc();
	Mesh* getMesh();
	int getEntitiesInRange();
	float getElasticity();

	void setMesh(Mesh* m);

	MyVector3* _position;
	MyVector3* _velocity;
	MyVector3* _acceleration;

protected:

	float _aggroRange;
	int _entitiesInRange;
	Mesh* mesh;
	const static float elasticity;
};

