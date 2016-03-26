#pragma once
class Timer
{
public:
	Timer();
	Timer(float f);
	~Timer();

	float getDt();
	void update();

private:
	float dt;
	float lastProcessed;
	float startTime;
};

