#include "Entity.h"
#include"Calculator.h"
#include "FinalVelocityCalc.h"
#include"DisplacementCalc.h"
#include <iostream>

using namespace std;

int main(){
	int k;
	cout << "Hello ! " << endl;

	vector<Entity*> tab;

	Entity* e1 = new Entity(0.0f, 0.0f, 0.0f, 2.0f);
	tab.push_back(e1);

	Entity* e2 = new Entity(1.0f, 0.0f, 0.0f, 0.5f);
	tab.push_back(e2);

	for (vector<Entity*>::size_type i = 0; i != tab.size(); i++){
		for (vector<Entity*>::size_type j = 0; j != tab.size(); j++){
			if (i != j){
				tab[i]->isInRange(tab[j]);
			}
		}
	}

	cout << "Entities in range" << endl;

	cout << e1->getEntitiesInRange() << endl;
	cout << e2->getEntitiesInRange() << endl;

	cout << "Multiplication" << endl;
	Vector3* test = new Vector3(1.0f, 1.0f, 1.0f);
	*test *= 3.0f;
	cout << *test;
	delete test;

	cout << "Normalisation of e1" << endl;

	Vector3* toNorm = new Vector3(2.0f, 2.0f, 2.0f);
	Vector3 normed=toNorm->normalise();
	cout << "toNorm: " << normed << endl;

	DisplacementCalc::launch();

	cin >> k;

	

	return 0;
}