#pragma once
#include "MyVector3.h"

class Calculator {
public:
	 virtual MyVector3* launch() = 0;

	Calculator();
	~Calculator();
};