#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "UnitCommand.h"

#include <iostream>

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
	int id;
	UnitType type;
	int maxHealth;
	int currentHealth;
	int speed;

	bool isSelected = false;
	std::vector<Command> commandQueue;

	//constructor
	Unit() {}
	Unit(std::string name, int id, UnitType type, int maxHealth, int speed, int circleSize)
		: name(name), id(id), type(type), maxHealth(maxHealth), currentHealth(maxHealth), speed(speed) {
		shape.setRadius(circleSize);
		shape.setFillColor(sf::Color::Green);
	}

	//set unit position
	bool setPosition(int x, int y) {
		shape.setPosition(sf::Vector2f(x, y));
		return true;
	}

	//select unit
	bool select() {
		if (isSelected) return false;
		else {
			isSelected = true;
			shape.setFillColor(sf::Color::Red);
			return true;
		}
	}

	//deselect unit
	bool deselect() {
		if (!isSelected) return false;
		else {
			isSelected = false;
			shape.setFillColor(sf::Color::Green);
			return true;
		}
	}

	//move unit
	bool move(Command command) {
		if (command.completed) {
			return true;
		}
		else {
			//move x
			if (shape.getPosition().x > command.endPoint.x) {
				setPosition(shape.getPosition().x - speed, shape.getPosition().y);
			}
			else if (shape.getPosition().x < command.endPoint.x) {
				setPosition(shape.getPosition().x + speed, shape.getPosition().y);
			}
			//move y
			if (shape.getPosition().y > command.endPoint.y) {
				setPosition(shape.getPosition().x, shape.getPosition().y - speed);
			}
			else if (shape.getPosition().y < command.endPoint.y) {
				setPosition(shape.getPosition().x, shape.getPosition().y + speed);
			}
			//complete
			if (shape.getPosition().x == command.endPoint.x
				&& shape.getPosition().y == command.endPoint.y) { 
				command.completed = true;
			}
			return false;
		}
	}
};

bool operator==(Unit a, Unit b) {
	if (a.name == b.name
		&& a.id == b.id
		&& a.type == b.type
		&& a.maxHealth == b.maxHealth
		&& a.speed == b.speed)
		return true;
	else return false;
}