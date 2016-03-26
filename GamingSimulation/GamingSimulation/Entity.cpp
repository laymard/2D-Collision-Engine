#include "Entity.h"

const float Entity::elasticity = 0.9f;
Entity::Entity()
{
}
Entity::Entity(float x, float y, float z, float range){
	_position = new MyVector3(x, y, z);
	_velocity = new MyVector3(0.0f, 0.0f, 0.0f);
	_acceleration = new MyVector3(0.0f, 0.0f, 0.0f);
	_aggroRange = range;
	_entitiesInRange = 0;
}





Entity::~Entity()
{
	delete _position;
	delete _acceleration;
	delete _velocity;
	delete mesh;
}

void Entity::isInRange(Entity* ent){
	if (this->_position->distanceTo(ent->getPos()) <= _aggroRange){ 
		_entitiesInRange++;
	}
		
}

Entity * Entity::generateTable(float w, float h)
{
	Entity* e = new Entity(0, 0, -500.0f, 1);
	e->mesh = Mesh::GenerateQuad(h, w);
	return e;
}

Entity * Entity::generateBound(float x1, float y1, float x2, float y2, Vector4 colour)
{
	Entity* e = new Entity(x1, y1, -500.0f,1);
	e->mesh = Mesh::GenerateLine(x1, y1, x2, y2, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
	return e;
}

MyVector3& Entity::getPos(){
	return *_position;
}
MyVector3& Entity::getVel() {
	return *_velocity;
}
MyVector3& Entity::getAcc() {
	return *_acceleration;
}

Mesh * Entity::getMesh()
{
	return mesh;
}


int Entity::getEntitiesInRange(){
	return _entitiesInRange;
}

float Entity::getElasticity()
{
	return elasticity;
}


void Entity::setMesh(Mesh * m)
{
	delete mesh;
	mesh = m;
}
