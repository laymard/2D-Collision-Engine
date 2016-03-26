#include "Table.h"



Table::Table()
{
}

Table::Table(MyVector3 * position, float w, float h, Vector4 colour):Entity(position,0.0f),width(w),height(h)
{
	mesh = Mesh::GenerateQuad(h, w, colour);
}


Table::Table(float x, float y, float z, float w, float h, Vector4 colour):Entity(x,y,z,0.0f),width(w),height(h)
{
	mesh = Mesh::GenerateQuad(h, w, colour);
}

Table::~Table()
{
}

void Table::setHeight(float h)
{
	height = h;
}

float Table::getHeight()
{
	return height;
}

void Table::setWidth(float w)
{
	width = w;
}

float Table::getWidth()
{
	return width;
}
