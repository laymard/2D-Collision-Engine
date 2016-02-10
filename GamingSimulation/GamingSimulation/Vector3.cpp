#include "Vector3.h"


Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

void Vector3::setPos(float x, float y, float z){
	_x = x;
	_y = y;
	_z = z;
}

 float Vector3::getX()const{
	return _x;
}

 float Vector3::getY()const{
	return _y;
}

 float Vector3::getZ()const{
	return _z;
}

void Vector3::setX(float pos){
	_x = pos;
}

void Vector3::setY(float pos){
	_y = pos;
}
void Vector3::setZ(float pos){
	_z = pos;
}

float Vector3::distanceTo(Vector3& vect){
	return sqrt(pow(getX() - vect.getX(), 2) + pow(getY() - vect.getY(), 2) + pow(getZ() - vect.getZ(), 2));
}

float Vector3::length(){
	Vector3* o = new Vector3(0.0f, 0.0f, 0.0f);

	float res = this->distanceTo(*o);
	delete o;
	return res;
}

Vector3& Vector3::normalise(){
	return *this / this->length();
}

void Vector3::input() {
	float x, y, z;
	cout << "Vector3::input(): input 3 float" << endl;
	cin >> x >> y >> z;

	Vector3* in = new Vector3(x, y, z);
	cout << "Created Vector3: " << *in << endl;
	delete in;
}