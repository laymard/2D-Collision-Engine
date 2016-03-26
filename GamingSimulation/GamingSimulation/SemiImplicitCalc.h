#pragma once
#include "Entity.h"
#include "Timer.h"

class SemiImplicitCalc
{
public:
	SemiImplicitCalc();
	~SemiImplicitCalc();

	static void update(Entity* e,Timer* t);
};

