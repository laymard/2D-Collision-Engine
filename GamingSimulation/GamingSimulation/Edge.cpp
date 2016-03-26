#include "Edge.h"



Edge::Edge()
{
}


Edge::Edge(float x, float y, float z, float n_x, float n_y, float n_z, float s, Vector4 colour):Entity(x,y,z,0.0f),size(s)
{
	normal = new MyVector3(n_x, n_y, n_z);
	*normal = normal->normalise();
	mesh = Mesh::GenerateLine(x, y, x + size*n_y, y + size*n_x, colour);
	distance = abs(normal->dotProduct(*_position));
	
}

Edge::~Edge()
{
}

float Edge::getSize()
{
	return size;
}

void Edge::setSize(float s)
{
	size = s;
}

MyVector3 * Edge::getNormal()
{
	return normal;
}

void Edge::setNormal(MyVector3 * n)
{
	normal = n;
	distance = abs(normal->dotProduct(*_position));
}

float Edge::getDistance()
{
	return distance;
}


