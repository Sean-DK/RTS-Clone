#pragma once

#include "stdafx.h"
#include "Point.h"

//Point Constructors
Point::Point(float x, float y)
	: x(x), y(y) {}

Point::Point(sf::Vector2f v) 
	: x(v.x), y(v.y) {}

//Overloads
Point* Point::operator=(Point point) {
	this->x = point.x;
	this->y = point.y;
	return this;
}