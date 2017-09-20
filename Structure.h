#pragma once

#include "StructureCommand.h"

enum StructureType {
	Base,
	Barracks,
};

class Structure {
public:
	StructureType type;
	std::vector<int> unitQueue;
	sf::CircleShape shape;
};