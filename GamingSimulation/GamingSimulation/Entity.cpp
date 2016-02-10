#include "Entity.h"


Entity::Entity()
{
}
Entity::Entity(float x, float y, float z, float range){
	_position = new Vector3(x, y, z);
	_aggroRange = range;
	_entitiesInRange = 0;
}



Entity::~Entity()
{
	delete _position;
}

void Entity::isInRange(Entity* ent){
	if (this->_position->distanceTo(ent->getPos()) <= _aggroRange){ 
		_entitiesInRange++;
	}
		
}

Vector3& Entity::getPos(){
	return *_position;
}

int Entity::getEntitiesInRange(){
	return _entitiesInRange;
}
