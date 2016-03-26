# include "Mesh.h"
#include <math.h>

Mesh::Mesh(void) {
	for (int i = 0; i < MAX_BUFFER; ++i) {
		bufferObject[i] = 0;

	}
	glGenVertexArrays(1, &arrayObject);

	numVertices = 0;
	vertices = NULL;
	colours = NULL;
	type = GL_TRIANGLES;

}

 Mesh ::~Mesh(void) {
 glDeleteVertexArrays(1, &arrayObject);
 glDeleteBuffers(MAX_BUFFER, bufferObject);
 delete[] vertices;
 delete[] colours;
}

 Mesh* Mesh::GenerateTriangle(){
	 Mesh* m = new Mesh();
	 m->numVertices = 3;

	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.5f, 0.0f);
	 m->vertices[1] = Vector3(0.5f, -0.5f, 0.0f);
	 m->vertices[2] = Vector3(-0.5f, -0.5f, 0.0f);

	 m->colours = new Vector4[m->numVertices];
	 m->colours[0] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	 m->colours[1] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	 m->colours[2] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	 m->BufferData();
	 return m;
 }
 Mesh * Mesh::GenerateSquare() {
	 Mesh* m = new Mesh();
	 m->numVertices = 6;

	 m->type = GL_TRIANGLE_FAN;

	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->vertices[1] = Vector3(-0.25f, -0.25f, 0.0f);
	 m->vertices[2] = Vector3(0.25f, -0.25f, 0.0f);
	 m->vertices[3] = Vector3(0.25f, 0.25f, 0.0f);
	 m->vertices[4] = Vector3(-0.25f, 0.25f, 0.0f);
	 m->vertices[5] = m->vertices[1];

	 m->colours = new Vector4[m->numVertices];
	 m->colours[0] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	 m->colours[1] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	 m->colours[2] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	 m->colours[3] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	 m->colours[4] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	 m->colours[5] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	 m->BufferData();
	 return m;
 }



 Mesh* Mesh::GenerateCircle(float r) {
	 int i = 1;
	 float angle;

	 Mesh* m = new Mesh();
	 m->type = GL_TRIANGLE_FAN;

	 m->numVertices = 100;
	 angle = (2.0f*M_PI) / (m->numVertices - 2);

	 m->vertices = new Vector3[m->numVertices];
	 m->colours = new Vector4[m->numVertices];

	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->colours[0] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	 for (i = 1; i < m->numVertices-1; i++) {
		 m->vertices[i] = Vector3(cos(angle*i)*r, sin(angle*i)*r, 0.0f);
		 m->colours[i] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	 }

	 m->vertices[m->numVertices - 1] = m->vertices[1];
	 m->colours[m->numVertices - 1] = m->colours[1];

	 m->BufferData();
	 return m;



 }

 Mesh * Mesh::GenerateCircle(float r, Vector4 colour)
 {
	 int i = 1;
	 float angle;

	 Mesh* m = new Mesh();
	 m->type = GL_TRIANGLE_FAN;

	 m->numVertices = 100;
	 angle = (2.0f*M_PI) / (m->numVertices - 2);

	 m->vertices = new Vector3[m->numVertices];
	 m->colours = new Vector4[m->numVertices];

	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->colours[0] = colour;

	 for (i = 1; i < m->numVertices - 1; i++) {
		 m->vertices[i] = Vector3(cos(angle*i)*r, sin(angle*i)*r, 0.0f);
		 m->colours[i] = colour;
	 }

	 m->vertices[m->numVertices - 1] = m->vertices[1];
	 m->colours[m->numVertices - 1] = colour;

	 m->BufferData();
	 return m;
 }

 Mesh * Mesh::GenerateQuad(float h, float w)
 {
	 Mesh* m = new Mesh();
	 m->numVertices = 6;
	 m->type = GL_TRIANGLE_FAN;

	 float hh = 0.5f * h;
	 float hw = 0.5f * w;


	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->vertices[1] = Vector3(-hw, -hh, 0.0f);
	 m->vertices[2] = Vector3(hw, -hh, 0.0f);
	 m->vertices[3] = Vector3(hw, hh, 0.0f);
	 m->vertices[4] = Vector3(-hw, hh, 0.0f);
	 m->vertices[5] = m->vertices[1];

	 m->colours = new Vector4[m->numVertices];
	 m->colours[0] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);
	 m->colours[1] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);
	 m->colours[2] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);
	 m->colours[3] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);
	 m->colours[4] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);
	 m->colours[5] = Vector4(0.33f, 0.61f, 0.34f, 1.0f);

	 m->BufferData();
	 return m;
 }

 Mesh * Mesh::GenerateQuad(float h, float w, Vector4 colour)
 {
	 Mesh* m = new Mesh();
	 m->numVertices = 6;
	 m->type = GL_TRIANGLE_FAN;

	 float hh = 0.5f * h;
	 float hw = 0.5f * w;


	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->vertices[1] = Vector3(-hw, -hh, 0.0f);
	 m->vertices[2] = Vector3(hw, -hh, 0.0f);
	 m->vertices[3] = Vector3(hw, hh, 0.0f);
	 m->vertices[4] = Vector3(-hw, hh, 0.0f);
	 m->vertices[5] = m->vertices[1];

	 m->colours = new Vector4[m->numVertices];
	 for (size_t i = 0; i < m->numVertices; i++)
	 {
		 m->colours[i] = colour;
	 }

	 m->BufferData();
	 return m;
 }

 Mesh * Mesh::GenerateLine(float l)
 {
	 Mesh* m = new Mesh();
	 m->numVertices = 2;
	 m->type = GL_LINES;

	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->vertices[1] = Vector3(0.0f, l, 0.0f);

	 m->colours = new Vector4[m->numVertices];
	 m->colours[0] = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	 m->colours[1] = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	 m->BufferData();
	 return m;
 }

 Mesh * Mesh::GenerateLine(float x1, float y1, float x2, float y2, Vector4 colour)
 {
	 Mesh* m = new Mesh();
	 m->numVertices = 2;
	 m->type = GL_LINES;
	 glLineWidth((GLfloat)2.0f);

	 m->vertices = new Vector3[m->numVertices];
	 m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	 m->vertices[1] = Vector3(x2 - x1, y2 - y1, 0.0f);

	 m->colours = new Vector4[m->numVertices];
	 m->colours[0] = colour;
	 m->colours[1] = colour;

	 m->BufferData();
	 glLineWidth((GLfloat)1.0f);
	 return m;

 }

 void Mesh::changeColour(Vector4 & colour)
 {
	 
	 for (int i= 0; i < numVertices; i++) {
		 colours[i] = colour;
	 }

	 //BufferData();
	 
 }



 void Mesh::BufferData(){
	 glBindVertexArray(arrayObject);
	 glGenBuffers(1, &bufferObject[VERTEX_BUFFER]);
	 glBindBuffer(GL_ARRAY_BUFFER, bufferObject[VERTEX_BUFFER]);
	 glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(Vector3), vertices, GL_STATIC_DRAW);
	 glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
	 glEnableVertexAttribArray(VERTEX_BUFFER);

	 if (colours){
		 glGenBuffers(1, &bufferObject[COLOUR_BUFFER]);
		 glBindBuffer(GL_ARRAY_BUFFER, bufferObject[COLOUR_BUFFER]);
		 glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(Vector4), colours, GL_STATIC_DRAW);
		 glVertexAttribPointer(COLOUR_BUFFER, 4, GL_FLOAT, GL_FALSE, 0, 0);
		 glEnableVertexAttribArray(COLOUR_BUFFER);
	 }
	 glBindVertexArray(0);
 }

 void Mesh::Draw(){
	 glBindVertexArray(arrayObject);
	 glDrawArrays(type, 0, numVertices);
	 glBindVertexArray(0);
 }
