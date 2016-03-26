#include "Game.h"



Game::Game()
{
}

Game::Game(Window& w,float f) {
	renderer =new  Renderer(w);
	timer = new Timer(f);

	background = new Table(0.0, 0.0, 0.0, 3.569, 1.778, Vector4(0.33f, 0.61f, 0.34f, 1.0f));
	entities.push_back(background);

	MyVector3* normal = new MyVector3(1.0f, 0.0f, 0.0f);
	Edge* w_b = new Edge(-3.569*50.0f, -1.778f*50.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.778f, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
	Edge* n_b = new Edge(3.569*50.0f, 1.778f*50.0f, 0.0f, 0.0f, -1.0f, 0.0f, 3.569f, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
	Edge* e_b = new Edge(3.569*50.0f, 1.778f*50.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.778f, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
	Edge* s_b = new Edge(-3.569*50.0f, -1.778f*50.0f, 0.0f, 0.0f, 1.0f, 0.0f, 3.569f, Vector4(1.0f, 1.0f, 1.0f, 1.0f));

	addEdge(w_b);
	addEdge(s_b);
	addEdge(n_b);
	addEdge(e_b);
}


Game::~Game()
{
	int i = 0;

	for (i = 0; i < entities.size(); i++) {
		delete entities[i];
	}

	delete timer;
	delete background;
	delete renderer;
}

void Game::update() {

	
	for (Entity* e : entities) {
		SemiImplicitCalc::update(e, timer);
	}
	checkDetection();
	applyCollisions();
	collisions.clear();
	timer->update();
	
	renderer->RenderScene(entities);
}

void Game::render()
{
	renderer->RenderScene();
}

void Game::addRandomBall()
{

	float x =((-3.3+ ((rand() % 33)*0.2f))*50.0f);
	float y = ((-1.5+((rand() % 15)*0.2))*50.0f);
	float z = -500.0f;

	Marble* e = new Marble(x, y, z, 1.0f, 0.02625f, 0.052f, Vector4(1.0f, 0.0f, 0.1f, 1.0f));
	addMarble(e);
}

void Game::addMarble(MyVector3 v)
{
	Marble* m = new Marble(v.getX(), v.getY(), v.getZ(), 10.0f, 0.02625f, 0.052f, Vector4(1.0f, 0.0f, 0.1f, 1.0f));
	addMarble(m);
}

void Game::checkDetection()
{
	float dsq;
	for (vector<Marble*>::iterator it1 = marbles.begin();it1!=marbles.end(); it1++) {
		for (vector<Marble*>::iterator it2 = marbles.begin(); it2!=marbles.end(); it2++)
		{
			if ((*it1) != (*it2)) {
				if ((*it1)->detectCollision((*it2))) {
					addSSResponseCollision((*it1), (*it2));
				}
			}
		}

		for (vector<Edge*>::iterator it3 = boundaries.begin(); it3!=boundaries.end(); it3++)
		{
			if ((*it1)->detectCollision((*it3))) {
				addSPResponseCollision((*it1), (*it3));
			}
		}
	}
}

void Game::applyCollisions()
{
	if (collisions.size() > 0) {
		for (vector<ResponseCollision*>::iterator it = collisions.begin(); it != collisions.end(); it++)
		{
			(*it)->apply();
		}
	}
}

void Game::addSSResponseCollision(Marble * m1, Marble * m2)
{
	if (!isAlreadyStored(m1, m2)) {
		SSResponseCollision* ssc = new SSResponseCollision(m1, m2);
		collisions.push_back(ssc);
		cout << "Creation of SSRC of marble " << m1 << " and marble " << m2 << endl;
	}
}

void Game::addSPResponseCollision(Marble * m, Edge * e)
{
	if (!isAlreadyStored(m,e)){}
	{
		SPResponseCollision* spc = new SPResponseCollision(m, e);
		collisions.push_back(spc);
		cout<<"Creation of SPRC of marble " << m << " and edge " << e << endl;
	}
}

void Game::addMarble(Marble * m)
{
	entities.push_back(m);
	marbles.push_back(m);
}

void Game::addEdge(Edge * e)
{
	entities.push_back(e);
	boundaries.push_back(e);
}

bool Game::isAlreadyStored(Entity * e1, Entity * e2)
{
	bool res = false;
	for (vector<ResponseCollision*>::iterator it = collisions.begin(); it != collisions.end() && !res; it++)
	{
		res = (*it)->alreadyExist(e1, e2);
	}

	return res;
}

Renderer * Game::getRenderer()
{
	return renderer;
}

Timer * Game::getTimer()
{
	return timer;
}

vector<Entity*> Game::getEntities()
{
	return entities;
}

vector<Edge*> Game::getBoundaries()
{
	return boundaries;
}

