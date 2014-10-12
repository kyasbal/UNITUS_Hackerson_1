#pragma once
#include <math.h>

class Vector3
{
public:
	Vector3(void);
	Vector3(float X, float Y, float Z);
	~Vector3(void);
	float Length();
	Vector3 Normalize();
	float DistanceTo(Vector3* vector);
	Vector3 CrossProductWith(Vector3* vector);
	Vector3 CrossProductWith(Vector3 vector);
	float DotProductWith(Vector3* vector);
	float DotProductWith(Vector3 vector);
	float X, Y, Z;
	Vector3 operator+ (Vector3* vector);
	Vector3 operator+ (Vector3 vector);
	Vector3& operator= (Vector3& vector);
	Vector3 operator- (Vector3* vector);
	Vector3 operator- (Vector3 vector);
	Vector3 operator/ (float a);
	Vector3 operator* (float a);
};