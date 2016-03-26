#include "Timer.h"



Timer::Timer()
{
}

Timer::Timer(float f):dt(1.0f/f),lastProcessed(0.0f),startTime(0.0f) {
}


Timer::~Timer()
{
}

float Timer::getDt() {
	return dt;
}

void Timer::update() {
	lastProcessed += dt;
}