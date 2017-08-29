#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Command.h"
#include "UnitCommand.h"

enum UnitType {
	Worker,
	Army
};

class Unit {
	sf::CircleShape shape;
	sf::FloatRect rect;

	std::string name;
	UnitType type;
	int maxHealth;
	int currentHealth;

	bool selected = false;
	std::vector<Command> commandQueue;
};