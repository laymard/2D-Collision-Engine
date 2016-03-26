#pragma once
#include "Calculator.h"
class FinalVelocityCalc:public Calculator
{
public:
	FinalVelocityCalc();
	~FinalVelocityCalc();

	static MyVector3* launch();
};

