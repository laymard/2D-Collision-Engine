#include "MyVector3.h"


MyVector3::MyVector3()
{
}


MyVector3::~MyVector3()
{
}

void MyVector3::setPos(float x, float y, float z){
	_x = x;
	_y = y;
	_z = z;
}

 float MyVector3::getX()const{
	return _x;
}

 float MyVector3::getY()const{
	return _y;
}

 float MyVector3::getZ()const{
	return _z;
}

void MyVector3::setX(float pos){
	_x = pos;
}

void MyVector3::setY(float pos){
	_y = pos;
}
void MyVector3::setZ(float pos){
	_z = pos;
}

float MyVector3::distanceTo(MyVector3& vect){
	return sqrt(pow(getX() - vect.getX(), 2) + pow(getY() - vect.getY(), 2) + pow(getZ() - vect.getZ(), 2));
}

float MyVector3::distanceToSq(MyVector3& vect) {
	return pow(getX() - vect.getX(), 2) + pow(getY() - vect.getY(), 2) + pow(getZ() - vect.getZ(), 2);
}

float MyVector3::length(){
	MyVector3* o = new MyVector3(0.0f, 0.0f, 0.0f);

	float res = this->distanceTo(*o);
	delete o;
	return res;
}

MyVector3 MyVector3::randomDirection()
{
	
	float param = rand() % 360;
	float x = cos(param*3.14159265358979323846*0.005555555);
	float y = sin(param*3.14159265358979323846*0.005555555);
	return MyVector3(x, y, 0.0f);
}

MyVector3& MyVector3::normalise(){
	return *this / this->length();
}

float MyVector3::dotProduct(MyVector3& v) {
	return _x*v.getX() + _y*v.getY() + _z*v.getZ();
}
void MyVector3::input() {
	float x, y, z;
	cout << "MyVector3::input(): input 3 float" << endl;
	cin >> x >> y >> z;

	MyVector3* in = new MyVector3(x, y, z);
	cout << "MyCreated Vector3: " << *in << endl;
	delete in;
}