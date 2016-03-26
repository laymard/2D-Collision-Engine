#include "SSResponseCollision.h"



SSResponseCollision::SSResponseCollision()
{
}

SSResponseCollision::SSResponseCollision(Marble * m1, Marble * m2)
{
	e1 = m1;
	e2 = m2;

	penetration = m1->getRadius() + m2->getRadius() - m1->getPos().distanceTo(m2->getPos());
	normal = new MyVector3(m1->getPos() - m2->getPos());
	*normal = (normal->normalise());
	contactPoint = new MyVector3(m1->getPos() - (*normal)*(m1->getRadius() - penetration));

	float num = -(1 + m1->getElasticity())*(m1->getVel() - m2->getVel()).dotProduct(*normal);
	float denum = normal->dotProduct(*normal)*(m1->getInvMass() + m2->getInvMass());

	energy = num / denum;
	
}


SSResponseCollision::~SSResponseCollision()
{
	delete contactPoint;
	delete normal;
}

void SSResponseCollision::apply()
{
	
	*(e1->_velocity) += (*normal)*(energy*e1->getInvMass());
	*(e2->_velocity) -= (*normal)*(energy*e2->getInvMass());
}

void SSResponseCollision::deletePenetration()
{
	*(e1->_position) -= (*normal)*penetration*0.5f;
	*(e2->_position) += (*normal)*penetration*0.5f;
}

bool SSResponseCollision::alreadyExist(Entity * a, Entity * b)
{
	return e1 == a && e2 == b || e1 == b && e2 == a;
}
