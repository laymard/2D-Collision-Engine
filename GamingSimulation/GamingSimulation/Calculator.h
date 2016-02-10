#pragma once
#include "Vector3.h"

class Calculator {
public:
	 virtual Vector3* launch() = 0;

	Calculator();
	~Calculator();
};