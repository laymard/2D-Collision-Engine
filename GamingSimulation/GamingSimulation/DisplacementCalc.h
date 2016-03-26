#pragma once
#include "Calculator.h"
class DisplacementCalc:public Calculator
{
public:
	DisplacementCalc();
	~DisplacementCalc();

	static MyVector3* launch();
};

