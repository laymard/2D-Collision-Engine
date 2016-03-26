#pragma once
#include "ResponseCollision.h"
#include "Marble.h"
#include "Edge.h"
class SPResponseCollision:public ResponseCollision
{
public:
	SPResponseCollision();
	SPResponseCollision(Marble* marble, Edge* edge);
	~SPResponseCollision();

	void apply();
	void deletePenetration();
	bool alreadyExist(Entity* e1, Entity* e2);


protected:
	Marble* m;
	Edge* e;

};

