#pragma once

#include "Unit.h"
#include "Point.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Unit;

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

	Command(CommandType);
};

class AttackCommand : public Command {
public:
	Unit* target;

	AttackCommand(Unit*);
};

class GatherCommand : public Command {
public:
	Resource* target;
	Point* endPoint;

	GatherCommand(Resource*);
};

class MoveCommand : public Command {
public:
	Point* endPoint;

	MoveCommand(Point*);
};