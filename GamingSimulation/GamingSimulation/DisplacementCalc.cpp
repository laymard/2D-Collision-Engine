#include "DisplacementCalc.h"



DisplacementCalc::DisplacementCalc()
{
}


DisplacementCalc::~DisplacementCalc()
{
}

Vector3 * DisplacementCalc::launch()
{
	float x1, x2, y1, y2, z1, z2;
	float t;

	cout << "Calcul of Final Velocity" << endl;
	cout << "Enter 3 floats for Initial Velocity : [ x y z ] " << endl;
	cin >> x1 >> y1 >> z1;

	cout << "Enter 3 floats for acceleration : [ x y z ] " << endl;
	cin >> x2 >> y2 >> z2;

	cout << "Enter time value" << endl;
	cin >> t;

	Vector3* u = new Vector3(x1, y1, z1);
	Vector3* a = new Vector3(x2, y2, z2);

	*u *= t;
	*a *= 0.5*t*t;
	*u += *a;

	cout << "Displacement v :" << endl;
	cout << *u;
	delete a;

	return u;
}
