#pragma once
#include "Entity.h"
#include "Edge.h"
class Marble: public Entity
{
public:
	Marble();
	Marble(MyVector3* position,float range,float radius,float mass, Vector4 colour );
	Marble(float x, float y, float z, float range, float radius,float mass, Vector4 colour);
	~Marble();

	bool detectCollision(Marble* mar);
	bool detectCollision(Edge* edg);

	void setMass(float m);
	float getMass();
	float getInvMass();

	void setRadius(float r);
	float getRadius();


private:
	float mass;
	float invMass;

	float radius;

};

