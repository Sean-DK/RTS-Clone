#pragma once

#include "Unit.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Unit;

class Point {
public:
	float x;
	float y;

	Point(float x, float y)
		: x(x), y(y) {}

	Point() {}
	Point* operator=(Point point) {
		this->x = point.x;
		this->y = point.y;
		return this;
	}
};

enum CommandType {
	Move,
	Attack,
	Gather
};

class Command {
public:
	CommandType type;
	bool completed;
	sf::RectangleShape shape;

	Command(CommandType type)
		: type(type), completed(false) {}
};

class AttackCommand : public Command {
public:
	Unit* target;

	AttackCommand(Unit* u)
		: Command(CommandType::Attack), target(u) {}
};

class GatherCommand : public Command {
public:
	Resource* target;
	Point* endPoint;

	GatherCommand(Resource* r)
		: Command(CommandType::Gather), target(r) {
		endPoint = new Point(0, 0);
	}
};

class MoveCommand : public Command {
public:
	Point* endPoint;

	MoveCommand(Point* p)
		: Command(CommandType::Move), endPoint(p) {}
};