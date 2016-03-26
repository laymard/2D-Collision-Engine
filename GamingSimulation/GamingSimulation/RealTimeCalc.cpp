#include "RealTimeCalc.h"



RealTimeCalc::RealTimeCalc()
{
}

RealTimeCalc::RealTimeCalc(MyVector3 * d, MyVector3 * v, MyVector3 * acc, float f)
{
	displacement = d;
	velocity = v;
	acceleration = acc;
	timer = new Timer(f);
}


RealTimeCalc::~RealTimeCalc()
{
	delete displacement;
	delete velocity;
	delete acceleration;
	delete timer;
}

void RealTimeCalc::updateExplicit()
{
	*displacement += (*velocity)*(timer->getDt());
	*velocity += (*acceleration)*(timer->getDt());
	timer->update();
}
