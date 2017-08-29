#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "UnitCommand.h"

enum UnitType {
	Worker,
	Army
};

class Unit {
public:
	sf::CircleShape shape;
	//TODO:  figure out rects
	//sf::FloatRect rect;

	std::string name;
	UnitType type;
	int maxHealth;
	int currentHealth;

	bool selected = false;
	std::vector<Command> commandQueue;

	//constructor
	Unit(std::string name, UnitType type, int maxHealth, int circleSize) 
		: name(name), type(type), maxHealth(maxHealth), currentHealth(maxHealth) {
		shape.setRadius(circleSize);
		shape.setFillColor(sf::Color::Green);
	}

	//set unit position
	void setPosition(int x, int y) {
		shape.setPosition(sf::Vector2f(x, y));
	}

};