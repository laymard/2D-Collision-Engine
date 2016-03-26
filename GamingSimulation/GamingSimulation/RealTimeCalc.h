#pragma once
#include "Timer.h"
#include"MyVector3.h"
class RealTimeCalc
{
public:
	RealTimeCalc();
	RealTimeCalc(MyVector3* d, MyVector3* v, MyVector3* acc, float f);
	~RealTimeCalc();
	void updateExplicit();

private:
	Timer* timer;
	MyVector3* displacement;
	MyVector3* velocity;
	MyVector3* acceleration;

};

