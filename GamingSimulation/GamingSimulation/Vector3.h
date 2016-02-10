#pragma once
#include <math.h>
#include <iostream>

using namespace std;
class Vector3
{
public:
	Vector3();
	~Vector3();

	Vector3::Vector3(float x, float y, float z) :_x(x), _y(y), _z(z){};

	void setPos(float x, float y, float z);

	float getX() const;
	float getY() const;
	float getZ() const;

	void setX(float p);
	void setY(float p);
	void setZ(float p);

	float distanceTo(Vector3& vect);
	float length();

	static void input();

	Vector3&  normalise();

	Vector3& operator*=(const float f){

		_x *= f;
		_y *= f;
		_z *= f;
		return *this;
	}

	Vector3& operator+=(const Vector3& v){
		_x += v._x;
		_y += v._y;
		_z += v._z;
		return *this;
	}

	Vector3& operator/=(const float f){

		float f_inv = 1.0f / f;
		_x *= f_inv;
		_y *= f_inv;
		_z *= f_inv;
		return *this;
	}


private:
	float _x;
	float _y;
	float _z;


};

inline Vector3 operator*(Vector3 v, const float f){
	v *= f;
	return v;
}

inline Vector3 operator+(Vector3 v, const Vector3& v2){
	v += v2;
	return v;
}

inline Vector3 operator/(Vector3 v, const float f){
	v /= f;
	return v;
}
inline ostream& operator<<(ostream& os, const Vector3& obj)
{
	os << "Vector3 [x:  " << obj.getX() << ", y: " << obj.getY() << ", z: " << obj.getZ() <<"]"<< endl;
	return os;
}
