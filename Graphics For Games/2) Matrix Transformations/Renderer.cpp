#include "Renderer.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent) {
	triangle = Mesh::GenerateTriangle();
	circle = Mesh::GenerateCircle(0.15f);

	currentShader = new Shader(SHADERDIR"MatrixVertex.glsl", SHADERDIR"colourFragment.glsl");

	if (!currentShader->LinkProgram()) {
		return;
	}

	init = true;

	SwitchToOrthographic();
}

Renderer::~Renderer(void) {
	delete triangle;
	delete circle;
}

void Renderer::SwitchToPerspective() {
	projMatrix = Matrix4::Perspective(1.0f, 10000.0f, (float)width / (float)height, 45.0f);
}

void Renderer::SwitchToOrthographic() {
	projMatrix = Matrix4::Orthographic(-1.0f, 10000.0f, width/4.0f,-width/4.0f,height/4.0f,-height/4.0f);
}

void Renderer::moveCircle() {

}

void Renderer::RenderScene() {
	Mesh* square = Mesh::GenerateSquare();
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(currentShader->GetProgram());

	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "projMatrix"), 1, false, (float*)&projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "viewMatrix"), 1, false, (float*)&viewMatrix);

	for (int i = 0; i < 3; ++i) {
		Vector3 tempPos = position;
		tempPos.z += (i*500.0f);
		tempPos.x -= (i*100.0f);
		tempPos.y -= (i*100.f);

		modelMatrix = Matrix4::Translation(Vector3(0.0f, 0.0f, -500.0f))*Matrix4::Rotation(1.0f, Vector3(1, 1, 0))*Matrix4::Scale(Vector3(100.0f, 100.0f, 100.0f));
		glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
		circle->Draw();

		modelMatrix = Matrix4::Translation(Vector3(0.0f, 200.0f, -500.0f))*Matrix4::Rotation(1.0f, Vector3(1, 1, 0))*Matrix4::Scale(Vector3(100.0f, 100.0f, 100.0f));
		glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
		circle->Draw();

		modelMatrix = Matrix4::Translation(Vector3(200.0f, 200.0f, -500.0f))*Matrix4::Rotation(1.0f, Vector3(1, 1, 0))*Matrix4::Scale(Vector3(100.0f, 100.0f, 100.0f));
		glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
		circle->Draw();

	}

	
	glUseProgram(0);

	SwapBuffers();

}

void Renderer::RenderScene(vector<Entity*> tab)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(currentShader->GetProgram());
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "projMatrix"), 1, false, (float*)&projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "viewMatrix"), 1, false, (float*)&viewMatrix);

	for (auto it = tab.begin(); it != tab.end();it++) {
		MyVector3* v = (*it)->_position;
		Vector3 v2 = Vector3(v->getX(), v->getY(), v->getZ());
		

		modelMatrix = Matrix4::Translation(v2)*Matrix4::Rotation(rotation, Vector3(0, 1, 0))*Matrix4::Scale(Vector3(100.0f, 100.0f, 100.0f));
		glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
		(*it)->getMesh()->Draw();
	}

	glUseProgram(0);

	SwapBuffers();
}

void Renderer::RenderScene(Entity * e)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(currentShader->GetProgram());
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "projMatrix"), 1, false, (float*)&projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "viewMatrix"), 1, false, (float*)&viewMatrix);

	MyVector3* v = e->_position;
	Vector3 v2 = Vector3(v->getX(), v->getY(), v->getZ());


	modelMatrix = Matrix4::Translation(v2)*Matrix4::Rotation(rotation, Vector3(0, 1, 0))*Matrix4::Scale(Vector3(500.0f, 500.0f,500.0f));
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
	e->getMesh()->Draw();

	glUseProgram(0);

	SwapBuffers();
	}
