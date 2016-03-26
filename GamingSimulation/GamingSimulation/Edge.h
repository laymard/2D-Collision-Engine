#pragma once
#include "Entity.h"
class Edge: public Entity
{
public:
	Edge();
	Edge(MyVector3* pos, MyVector3* n, float s, Vector4 colour);
	Edge(float x, float y, float z, MyVector3* n, float s, Vector4 colour);
	Edge(float x, float y, float z, float n_x, float n_y, float n_z, float s, Vector4 colour);
	~Edge();

	float getSize();
	void setSize(float s);

	MyVector3* getNormal();
	void setNormal(MyVector3* n);

	float getDistance();

private:
	MyVector3* normal;
	float distance;
	float size;
};

