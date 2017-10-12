#pragma once
#include "StructureCommand.h"
#include "Unit.h"

//Forward declaration
class Controller;
class Unit;

//StructureType
enum StructureType {
	Base,
	Barracks,
	Factory
};

//Structure
//TODO: add health and armor and stuff based on structure type
class Structure {
private:
	StructureType type;
	int structureID;
	std::vector<Unit*> unitQueue;
	sf::CircleShape shape;
	Controller* controller;

public:
	//Constructor
	Structure() {}
	Structure(StructureType, int, Controller*);

	//Accesors
	const sf::CircleShape* getShape() { return &shape; }
	StructureType getType() { return type; }
	std::vector<Unit*> getUnitQueue() { return unitQueue; }

	//Mutators
};