//TODO: make member variables private and add accessors

#pragma once

#include "Unit.h"
#include "Point.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Forward declarations
class Unit;

//CommandType
enum CommandType {
	Attack,
	Gather,
	Move,
	Patrol,
};

//Command
class Command {
public:
	CommandType type;
	bool completed;
	sf::RectangleShape shape;

	Command(CommandType);
};

//AttackCommand
class AttackCommand : public Command {
public:
	Unit* target;

	AttackCommand(Unit*);
};

//GatherCommand
class GatherCommand : public Command {
public:
	Resource* target;
	Point* endPoint;

	GatherCommand(Resource*);
};

//MoveCommand
class MoveCommand : public Command {
public:
	Point endPoint;

	MoveCommand(Point);
};

//PatrolCommand
class PatrolCommand : public Command {
public:
	Point startPoint;
	Point endPoint;

	PatrolCommand(Point, Point);
};