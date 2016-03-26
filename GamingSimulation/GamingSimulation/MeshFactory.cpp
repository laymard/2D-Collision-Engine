#include "MeshFactory.h"
#include <iostream>

using namespace std;

MeshFactory MeshFactory::m_instance = MeshFactory();

MeshFactory::MeshFactory()
{
	cout << "MeshFactory Created" << endl;
}


MeshFactory::~MeshFactory()
{
	cout << "Destruction" << endl;
}

MeshFactory& MeshFactory::Instance() {
	return m_instance;
}

Mesh* MeshFactory::GenerateCircle(float r, Vector4 colour) {
	vector<Mesh*>::iterator it = circles.begin();
	for (it; it < circles.end(); it++) {
	}

}
