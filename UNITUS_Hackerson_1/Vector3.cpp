#include "Vector3.h"

Vector3::Vector3(void)
{
}

Vector3::Vector3(float X, float Y, float Z){
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

// Returns the length of the vector
float Vector3::Length(){
	return sqrt(X * X + Y * Y + Z * Z);
}

// Normalizes the vector
Vector3 Vector3::Normalize(){
	Vector3 vector;
	float length = this->Length();

	if (length != 0){
		vector.X = X / length;
		vector.Y = Y / length;
		vector.Z = Z / length;
	}

	return vector;
}

float Vector3::DistanceTo(Vector3* v){
	float distance = sqrt(pow(v->X - X, 2) + pow(v->Y - Y, 2) + pow(v->Z - Z, 2));
	return distance;
}

Vector3 Vector3::CrossProductWith(Vector3* v){
	Vector3 p;
	p.X = Y*v->Z - Z*v->Y;
	p.Y = Z*v->X - X*v->Z;
	p.Z = X*v->Y - Y*v->X;
	return p;
}

float Vector3::DotProductWith(Vector3* v){
	return (X*v->X + Y*v->Y + Z*v->Z);
}

Vector3 Vector3::CrossProductWith(Vector3 v){
	Vector3 p;
	p.X = Y*v.Z - Z*v.Y;
	p.Y = Z*v.X - X*v.Z;
	p.Z = X*v.Y - Y*v.X;
	return p;
}

float Vector3::DotProductWith(Vector3 v){
	return (X*v.X + Y*v.Y + Z*v.Z);
}

Vector3::~Vector3(void)
{
}

Vector3 Vector3::operator+ (Vector3* v){
	Vector3 s;
	s.X = X + v->X;
	s.Y = Y + v->Y;
	s.Z = Z + v->Z;
	return s;
}

Vector3 Vector3::operator+ (Vector3 v){
	Vector3 s;
	s.X = X + v.X;
	s.Y = Y + v.Y;
	s.Z = Z + v.Z;
	return s;
}

Vector3& Vector3::operator= (Vector3& v){
	X = v.X;
	Y = v.Y;
	Z = v.Z;
	return *this;
}

Vector3 Vector3::operator- (Vector3* v){
	Vector3 s;
	s.X = X - v->X;
	s.Y = Y - v->Y;
	s.Z = Z - v->Z;
	return s;
}

Vector3 Vector3::operator- (Vector3 v){
	Vector3 s;
	s.X = X - v.X;
	s.Y = Y - v.Y;
	s.Z = Z - v.Z;
	return s;
}

Vector3 Vector3::operator/ (float a){
	Vector3 s;
	s.X = s.Y = s.Z = 0;
	if (a != 0)
	{
		s.X = X / a;
		s.Y = Y / a;
		s.Z = Z / a;
	}
	return s;
}

Vector3 Vector3::operator* (float a){
	Vector3 s;
	s.X = X*a;
	s.Y = Y*a;
	s.Z = Z*a;
	return s;
}