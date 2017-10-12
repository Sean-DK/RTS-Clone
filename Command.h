//TODO: make member variables private and add accessors

#pragma once
#include "Unit.h"
#include "Point.h"
#include "Resource.h"
#include "Structure.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Forward declarations
class Unit;
enum StructureType;

//CommandType
enum CommandType {
	Attack,
	Build,
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

//BuildCommand
class BuildCommand : public Command {
public:
	StructureType structType;
	Point dest;

	BuildCommand(StructureType, Point);
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