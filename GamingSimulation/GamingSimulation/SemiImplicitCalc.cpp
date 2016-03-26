#include "SemiImplicitCalc.h"



SemiImplicitCalc::SemiImplicitCalc()
{
}


SemiImplicitCalc::~SemiImplicitCalc()
{
}

void SemiImplicitCalc::update(Entity* e,Timer* t) {
	*(e->_velocity) += *(e->_acceleration)*t->getDt();
	*(e->_position) += *(e->_velocity)*t->getDt();

}
