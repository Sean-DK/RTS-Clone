#pragma once

enum CommandType {
	Move,
	Attack,
	Gather
};

class Point {
public:
	int x;
	int y;

	Point() {}
	Point(int x, int y)
		: x(x), y(y) {}

	Point* operator=(Point point) {
		this->x = point.x;
		this->y = point.y;
		return this;
	}
};

//TODO: figure out attack commands
class Command {
public:
	CommandType type;
	Point startPoint;
	Point endPoint;
	//Unit target;
	bool completed = false;

	Command() {}
	Command(CommandType type, Point endPoint)
		: type(type), endPoint(endPoint) {}
	//Command(CommandType type, Unit target)
		//: type(type), target(target) {}


};