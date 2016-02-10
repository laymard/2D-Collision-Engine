#pragma once
#include "Calculator.h"
class DisplacementCalc:public Calculator
{
public:
	DisplacementCalc();
	~DisplacementCalc();

	static Vector3* launch();
};

