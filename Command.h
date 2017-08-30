#pragma once

#include "Unit.h"

enum CommandType {
	Move,
	Attack
};

class Point {
public:
	int x;
	int y;

	Point() {}
	Point(int x, int y)
		: x(x), y(y) {}

};

class Command {
public:
	CommandType type;
	Point endPoint;
	//Unit target;
	bool completed = false;

	Command() {}
	Command(CommandType type, Point endPoint)
		: type(type), endPoint(endPoint) {}
	//Command(CommandType type, Unit target)
		//: type(type), target(target) {}

};