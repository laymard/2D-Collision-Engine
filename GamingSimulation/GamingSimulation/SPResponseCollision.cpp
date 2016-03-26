#include "SPResponseCollision.h"



SPResponseCollision::SPResponseCollision()
{
}

SPResponseCollision::SPResponseCollision(Marble * marble, Edge * edge)
{
	m = marble;
	e = edge;
	normal = new MyVector3(*(edge->getNormal()));
	penetration = marble->getRadius() - (edge->getNormal()->dotProduct(marble->getPos()) + edge->getDistance());
	contactPoint = new MyVector3(marble->getPos() - (*normal)*(marble->getRadius() - penetration));

	float num = -(1 + m->getElasticity())*(marble->getVel().dotProduct(*normal));
	float denum = normal->dotProduct(*normal*marble->getInvMass());

	energy = num / denum;
}


SPResponseCollision::~SPResponseCollision()
{
	delete normal;
	delete contactPoint;
}

void SPResponseCollision::apply()
{
	//*(m->_position) += (*normal)*penetration;
	*(m->_velocity) += (*normal)*(energy*m->getInvMass());
}

void SPResponseCollision::deletePenetration()
{
}

bool SPResponseCollision::alreadyExist(Entity * e1, Entity * e2)
{
	return m == e1 && e == e2 || m == e2 && e == e1;
}
