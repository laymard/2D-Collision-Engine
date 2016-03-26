#pragma once

#include "../../nclgl/OGLRenderer.h"
#include "../../GamingSimulation/GamingSimulation/Entity.h"

class Renderer :public OGLRenderer {
public:
	Renderer(Window &parent);
	virtual ~Renderer(void);
	virtual void RenderScene();
	virtual void RenderScene(vector<Entity*> tab);
	virtual void RenderScene(Entity* e);

	void SwitchToPerspective();
	void SwitchToOrthographic();

	void moveCircle();

	inline void SetScale(float s) { scale = s; }
	inline void SetRotation(float r) { rotation = r; }
	inline void SetPosition(Vector3 p) { position = p; }

protected:
	Mesh* triangle;
	float scale;
	float rotation;
	Vector3 position;
	Mesh* circle;
};