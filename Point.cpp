#pragma once

#include "stdafx.h"
#include "Point.h"

Point* Point::operator=(Point point) {
	this->x = point.x;
	this->y = point.y;
	return this;
}

Point::Point(float x, float y)
	: x(x), y(y) {}
