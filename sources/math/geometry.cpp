#include "math/geometry.h"


Point::Point(int x, int y): x(x), y(y) {}

Point& Point::operator+=(const Vector& vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}

Point& Point::operator-=(const Vector& vector) {
	x -= vector.x;
	y -= vector.y;
	return *this;
}


Vector::Vector(int x, int y): x(x), y(y) {}

Vector& Vector::operator+=(const Vector& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector& Vector::operator-=(const Vector& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector& Vector::operator*=(int coefficient) {
	x *= coefficient;
	y *= coefficient;
	return *this;
}

Vector& Vector::operator/=(int coefficient) {
	x /= coefficient;
	y /= coefficient;
	return *this;
}

int Vector::lengthSquared() const {
	return x * x + y * y;
}

Vector Vector::simplified() const {
	Vector result = *this;
	result /= gcd(std::abs(x), std::abs(y));
	return result;
}


Point operator+(const Point& point, const Vector& vector) {
	Point result = point;
	result += vector;
	return result;
}

Point operator-(const Point& point, const Vector& vector) {
	Point result = point;
	result -= vector;
	return result;
}


Vector operator+(const Vector& first, const Vector& second) {
	Vector result = first;
	result += second;
	return result;
}

Vector operator-(const Vector& first, const Vector& second) {
	Vector result = first;
	result -= second;
	return result;
}

Vector operator*(const Vector& vector, int coefficient) {
	Vector result = vector;
	result *= coefficient;
	return result;
}

Vector operator/(const Vector& vector, int coefficient) {
	Vector result = vector;
	result /= coefficient;
	return result;
}