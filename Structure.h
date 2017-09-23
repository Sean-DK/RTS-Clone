#pragma once

#include "StructureCommand.h"

//idk why this needs to be here but it doesn't work without it
class Controller;

enum StructureType {
	Base,
	Barracks,
	Factory
};

class Structure {
private:
	StructureType type;
	std::vector<int> unitQueue;
	sf::CircleShape shape;
	Controller* controller;

public:
	const sf::CircleShape* getShape() { return &shape; }
};