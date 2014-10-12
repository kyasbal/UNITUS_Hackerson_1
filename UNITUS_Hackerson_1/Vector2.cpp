#pragma once
#include <cmath>
class Vector2 {
public:
	double x, y;
	Vector2() :x(0), y(0){
	}
	Vector2(const Vector2& v) :x(v.x), y(v.y){
	}
	Vector2(double x, double y) :x(x), y(y){
	}
	Vector2& operator = (const Vector2& v){
		x = v.x;
		y = v.y;
		return *this;
	}
	bool operator == (const Vector2& v) const{
		return (x == v.x && y == v.y);
	}
	bool operator != (const Vector2& v) const{
		return (x != v.x || y != v.y);
	}
	const Vector2& operator+() const{
		return *this;
	}
	Vector2& operator+(){
		return *this;
	}
	Vector2 operator-() const{
		return Vector2(-x, -y);
	}
	Vector2& operator+=(const Vector2& v){
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2 operator+(const Vector2& v) const{
		return Vector2(x + v.x, y + v.y);
	}
	Vector2& operator+(Vector2&& v) const{
		return v += *this;
	}
	Vector2& operator-=(const Vector2& v){
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Vector2 operator-(const Vector2& v) const{
		return Vector2(x - v.x, y - v.y);
	}
	Vector2& operator-(Vector2&& v) const{
		v.x = -v.x;
		v.y = -v.y;
		v += *this;
		return v;
	}
	Vector2& operator*=(double k){
		x *= k;
		y *= k;
		return *this;
	}
	Vector2 operator*(double k) const{
		return Vector2(x * k, y * k);
	}
	Vector2& operator/=(double k){
		x /= k;
		y /= k;
		return *this;
	}
	Vector2 operator/(double k) const{
		return Vector2(x / k, y / k);
	}
	double operator*(const Vector2& v) const{
		return (x * v.x) + (y * v.y);
	}
	double operator/(const Vector2& v) const{
		return (x * v.y) - (y * v.x);
	}
	double length() const{
		return std::sqrt((*this) * (*this));
	}
	Vector2 unit() const{
		const double len = length();
		return len == 0 ? *this : *this / len;
	}
	double angle() const{
		return std::atan2(y, x);
	}
};