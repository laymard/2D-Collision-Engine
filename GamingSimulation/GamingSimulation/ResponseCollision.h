#pragma once
#include "MyVector3.h"
#include "Entity.h"
class ResponseCollision
{
public:
	ResponseCollision();
	~ResponseCollision();

	virtual bool alreadyExist(Entity* a, Entity* b)=0;
	virtual void apply()=0;
	virtual void deletePenetration()=0;


protected:

	float penetration;
	MyVector3* contactPoint;
	MyVector3* normal;
	float energy;
};

