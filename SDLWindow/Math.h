#pragma once

#include <iostream>

struct Vector2f
{
	Vector2f() : x(0.0f), y(0.0f) {}
	Vector2f(float _x, float _y) : x(_x), y(_y) {}
	void print();
	float x, y;
};
