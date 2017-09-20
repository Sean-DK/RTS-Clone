#pragma once

#include "Controller.h"
#include "StructureCommand.h"

//idk why this needs to be here but it doesn't work without it
class Controller;

enum StructureType {
	Base,
	Barracks,
};

class Structure {
private:
	StructureType type;
	std::vector<int> unitQueue;
	sf::CircleShape shape;
	Controller* controller;

public:

};