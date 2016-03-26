# pragma once
# include "OGLRenderer.h"
#include <math.h>
#define _USE_MATH_DEFINES

enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, MAX_BUFFER
};
class Mesh {
public:
	Mesh(void);
	~Mesh(void);

	virtual void Draw();
	static Mesh * GenerateTriangle();

	static Mesh * GenerateSquare();

	static Mesh * GenerateCircle(float r);
	static Mesh * GenerateCircle(float r, Vector4 colour);

	static Mesh * GenerateQuad(float h, float w);
	static Mesh * GenerateQuad(float h, float w, Vector4 colour);

	static Mesh * GenerateLine(float l);
	static Mesh * GenerateLine(float x1, float y1, float x2, float y2, Vector4 colour);

	void changeColour(Vector4& colour);
	

protected:
	void BufferData();

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	GLuint numVertices;
	GLuint type;

	Vector3 * vertices;
	Vector4 * colours;

};
