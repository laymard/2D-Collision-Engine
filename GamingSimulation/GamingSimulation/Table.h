#pragma once
#include "Entity.h"
class Table:public Entity
{
public:
	Table();
	Table(MyVector3* position, float width, float height, Vector4 colour);
	Table(float x, float y, float z, float width, float height, Vector4 colour);
	~Table();

	void setHeight(float h);
	float getHeight();

	void setWidth(float w);
	float getWidth();

private:
	float height;
	float width;
};

