#pragma once

#include <math.h>

#include "math/utilities.h"


struct Point;
struct Vector;


struct Point {
	int x;
	int y;
	Point(int x = 0, int y = 0);
	Point& operator+=(const Vector&);
	Point& operator-=(const Vector&);
};

struct Vector {
	int x;
	int y;
	Vector(int x = 0, int y = 0);
	Vector& operator+=(const Vector&);
	Vector& operator-=(const Vector&);
	Vector& operator*=(int);
	Vector& operator/=(int);
	int lengthSquared() const;
	Vector simplified() const;
};


Point operator+(const Point&, const Vector&);
Point operator-(const Point&, const Vector&);

Vector operator+(const Vector&, const Vector&);
Vector operator-(const Vector&, const Vector&);
Vector operator*(const Vector&, int);
Vector operator/(const Vector&, int);