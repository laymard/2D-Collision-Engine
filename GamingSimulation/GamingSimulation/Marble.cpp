#include "Marble.h"



Marble::Marble()
{
}

Marble::Marble(MyVector3 * position, float range, float radius, float m, Vector4 colour):Entity(position,range)
{
	mesh = Mesh::GenerateCircle(radius, colour);
	mass = m;
	invMass = 1 / m;
	this->radius = radius;
}

Marble::Marble(float x, float y, float z, float range, float radius,float m, Vector4 colour):Entity(x,y,z,range)
{
	mesh = Mesh::GenerateCircle(radius, colour);
	mass = m;
	invMass = 1 / m;
	this->radius = radius;
}


Marble::~Marble()
{
	delete mesh;
}

bool Marble::detectCollision(Marble * mar)
{
	float dsq = getPos().distanceToSq(mar->getPos());
	if (dsq < pow(getRadius()*100.0f+mar->getRadius()*100.0f,2)) { //*100.0f because of the size model matrix on Render.cpp
		cout << "S-S Detection between " << this << " and " << mar << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Marble::detectCollision(Edge * edg)
{
	if (pow(edg->getNormal()->dotProduct(getPos()) + edg->getNormal()->dotProduct(edg->getPos()),2) < pow(getRadius()*100.0f,2)) {
		//cout<<"S-P Detection between " << this << " and " << edg << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Marble::setMass(float m)
{
	mass = m;
	invMass = 1 / m;
}

float Marble::getMass()
{
	return mass;
}

float Marble::getInvMass()
{
	return invMass;
}

void Marble::setRadius(float r)
{
	radius = r;
}

float Marble::getRadius()
{
	return radius;
}
