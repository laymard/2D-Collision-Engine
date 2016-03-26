#include "Renderer.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{
	triangle = Mesh::GenerateTriangle();
	square = Mesh::GenerateSquare();
	circle = Mesh::GenerateCircle(0.5f);

	currentShader = new Shader(SHADERDIR"basicVertex.glsl",
		SHADERDIR"colourFragment.glsl");

	if(!currentShader->LinkProgram()) {
		return;
	}

	init = true;
}
Renderer::~Renderer(void)	{
	delete triangle;
	delete square;
	delete circle;
}

void Renderer::RenderScene()	{
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);	

	glUseProgram(currentShader->GetProgram());
	triangle->Draw();
	glUseProgram(0);

	glUseProgram(currentShader->GetProgram());
	square->Draw();
	glUseProgram(0);

	glUseProgram(currentShader->GetProgram());
	circle->Draw();
	glUseProgram(0);

	SwapBuffers();	
}

