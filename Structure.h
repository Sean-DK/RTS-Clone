#pragma once

#include "StructureCommand.h"

//Forward declaration
class Controller;

//StructureType
enum StructureType {
	Base,
	Barracks,
	Factory
};

//Structure
class Structure {
private:
	StructureType type;
	std::vector<int> unitQueue;
	sf::CircleShape shape;
	Controller* controller;

public:
	//Accesors
	const sf::CircleShape* getShape() { return &shape; }
};