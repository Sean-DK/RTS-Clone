#pragma once

//Point
class Point {
public:
	float x;
	float y;

	Point() {}
	Point(float, float);

	Point* operator=(Point);
};
