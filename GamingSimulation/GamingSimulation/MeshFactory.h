#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H
#include "../../nclgl/Mesh.h"

class MeshFactory
{
public:
	static MeshFactory& Instance();
	Mesh* GenerateCircle(float r,Vector4 colour);
	Mesh* GenerateQuad(Vector4 colour);

private:
	MeshFactory& operator= (const MeshFactory&){}
	MeshFactory (const MeshFactory&){}

	static MeshFactory m_instance;

	MeshFactory();
	~MeshFactory();
	vector<Mesh*> circles;
	vector<Mesh*> quads;
};

#endif