#pragma once
#include "ResponseCollision.h"
#include "Marble.h"
class SSResponseCollision:public ResponseCollision
{
public:
	SSResponseCollision();
	SSResponseCollision(Marble* m1, Marble* m2);
	~SSResponseCollision();
	void apply();
	void deletePenetration();
	bool alreadyExist(Entity* a, Entity* b);

protected:
	Marble* e1;
	Marble* e2;

};

