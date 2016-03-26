#include "Entity.h"
#include"Calculator.h"
#include "FinalVelocityCalc.h"
#include"DisplacementCalc.h"
#include "Game.h"
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	int nbMarbles;
	cout << "How many marbles ? " << endl;
	cin >> nbMarbles;
	Window w("Vertex Transformation!", 1280, 720, false);
	if (!w.HasInitialised()) {
		return -1;
	}

	Game* game = new Game(w, 120.0f);
	Mesh* square = Mesh::GenerateSquare();
	if (!game->getRenderer()->HasInitialised()) {
		return -1;
	}


	/*for (int i = 0; i < nbMarbles; i++) {
		game->addRandomBall();
		*(game->getEntities()[game->getBoundaries().size() + 1 + i]->_velocity) = MyVector3::randomDirection()*40.0f*(i+1);
	}*/

	for (int i = 0; i < 13; i++)
	{
		game->addMarble(MyVector3(-50.0f, (-1.6f*50.0f)+(i+1) * 10,-500.0f));
		game->addMarble(MyVector3(50.0f, (-1.6f * 50.0f) +(i+1) * 10, -500.0f));
		*(game->getEntities()[game->getBoundaries().size() + 1 + i*2]->_velocity) = MyVector3(10 * (i+1), 0, 0);
		*(game->getEntities()[game->getBoundaries().size() + 2 + i*2]->_velocity) = MyVector3(10 * -(i + 1), 0, 0);
	}
	
	game->getRenderer()->SwitchToOrthographic();
	while (w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)) {
		game->update();
	}


	delete game;

	return 0;
}