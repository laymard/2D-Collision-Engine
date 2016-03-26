#pragma once
#include "Entity.h"
#include "Marble.h"
#include "Table.h"
#include "Timer.h"
#include "Edge.h"
#include "SemiImplicitCalc.h"
#include "ResponseCollision.h"
#include "SSResponseCollision.h"
#include "SPResponseCollision.h"
#include <stdio.h>
#include <time.h>
#include <ctime>
#include "../../Graphics For Games/2) Matrix Transformations/Renderer.h"

class Game
{
public:
	Game();
	Game(Window& w,float f);
	~Game();

	void update();
	void render();

	void addRandomBall();
	void addMarble(MyVector3 m);
	void checkDetection();
	void applyCollisions();

	void addSSResponseCollision(Marble* m1, Marble* m2);
	void addSPResponseCollision(Marble* m, Edge* e);
	void addMarble(Marble* m);
	void addEdge(Edge* e);
	bool isAlreadyStored(Entity* e1, Entity* e2);

	Renderer* getRenderer();
	Timer* getTimer();
	vector<Entity*> getEntities();
	vector<Edge*> getBoundaries();
	


private:
	vector<Entity*> entities;
	vector<Edge*> boundaries;
	vector<Marble*> marbles;
	vector<ResponseCollision*> collisions;
	Entity* background;
	Renderer* renderer;
	Timer* timer;
};

