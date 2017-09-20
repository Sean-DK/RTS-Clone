#pragma once

#include <vector>
#include "Command.h"
#include "Controller.h"
#include "UnitCommand.h"

#include <iostream>

//idk why this needs to be here but it doesn't work without it
class Controller;

enum UnitType {
	Worker,
	Army
};

enum UnitName {
	SCV,
	Marine,
	Medic,
	Tank,
};

//TODO: do inheritance for unit types
class Unit {
private:
	Controller* controller; //Workers ONLY
	sf::RectangleShape shape;
	UnitType type;
	UnitName name;
	int unitID;
	int maxHealth;
	int currentHealth;
	double speed;
	bool selected = false;
	bool gathering = false; //Workers ONLY
	std::vector<Command*> commandQueue;

public:
	//constructor
	Unit() {}
	Unit(UnitName n, int id)
		: name(n), unitID(id) {
		switch (this->name) {
		case UnitName::Marine:
			type = UnitType::Army;
			maxHealth = 50;
			currentHealth = 50;
			speed = 1;
			break;
		case UnitName::Medic:
			type = UnitType::Army;
			maxHealth = 50;
			currentHealth = 50;
			speed = 1;
			break;
		case UnitName::Tank:
			type = UnitType::Army;
			maxHealth = 75;
			currentHealth = 75;
			speed = 0.5;
			break;
		case UnitName::SCV:
			type = UnitType::Worker;
			maxHealth = 25;
			currentHealth = 25;
			speed = 1;
			shape.setSize(sf::Vector2f(32, 32));
			break;
		}
	}

	//Getters
	//TODO: delete any unused when done working
	const sf::RectangleShape* getShape() { return &shape; }
	const UnitType getType() { return type; }
	const UnitName getName() { return name; }
	const int getID() { return unitID; }
	const int getMaxHealth() { return maxHealth; }
	const int getCurrentHealth() { return currentHealth; }
	const double getSpeed() { return speed; }
	const bool isSelected() { return selected; }
	const bool isGathering() { return gathering; }
	const Command* getCommand(int i) { return commandQueue[i]; }
	const bool commandEmpty() { return commandQueue.empty(); }

	//Setters
	void setPosition(Point* p) { shape.setPosition(p->x, p->y); }
	void setPosition(float x, float y) { shape.setPosition(x, y); }
	void setHealth(int h) { currentHealth = h; }
	void select() {
		if (!selected) {
			selected = true;
			shape.setFillColor(sf::Color::Red);
		}
	}
	void deselect() {
		if (selected) {
			selected = false;
			shape.setFillColor(sf::Color::White);
		}
	}
	void setCommand(Command* c) {
		if (commandQueue.empty()) { commandQueue.push_back(c); }
		else {
			commandQueue.clear();
			commandQueue.push_back(c);
		}
	}
	void addCommand(Command* c) {
		commandQueue.push_back(c);
	}

	//Command engine
	void executeCommand() {
		if (!commandQueue.empty()) {
			switch (commandQueue.front()->type) {
			case CommandType::Attack:
				attack(static_cast<AttackCommand*>(commandQueue.front()));
				break;
			case CommandType::Gather:
				gather(static_cast<GatherCommand*>(commandQueue.front()));
				break;
			case CommandType::Move:
				move(static_cast<MoveCommand*>(commandQueue.front()));
				break;
			}
		}
	}

	//Attack command
	void attack(AttackCommand* command) {}

	//Gather command
	//TODO: fix pathing and timing
	//TODO: when giving "Gather" command and holding shift the unit walks offscreen and is lost
	void gather(GatherCommand* command) {
		//Check for completion
		if (commandQueue.front()->completed) {
			//If there is a command waiting, stop gathering
			if (commandQueue.size() > 1) {
				commandQueue.erase(commandQueue.begin());
			}
			//Otherwise continue gathering
			else {
				commandQueue.front()->completed = false;
			}
		}
		else {
			//If the unit is NOT currently holding a resource (AKA gathering), move towards resource
			//TODO: change variable name of "gathering"
			if (!gathering) {
				command->endPoint->x = command->target->getShape()->getPosition().x;
				command->endPoint->y = command->target->getShape()->getPosition().y;
			}
			else {
				command->endPoint->x = 0;
				command->endPoint->y = 0;
			}
			//Move x
			if (shape.getPosition().x > command->endPoint->x) {
				setPosition(shape.getPosition().x - speed, shape.getPosition().y);
			}
			else if (shape.getPosition().x < command->endPoint->x) {
				setPosition(shape.getPosition().x + speed, shape.getPosition().y);
			}
			//Move y
			if (shape.getPosition().y > command->endPoint->y) {
				setPosition(shape.getPosition().x, shape.getPosition().y - speed);
			}
			else if (shape.getPosition().y < command->endPoint->y) {
				setPosition(shape.getPosition().x, shape.getPosition().y + speed);
			}
			if (shape.getPosition().x == command->endPoint->x
				&& shape.getPosition().y == command->endPoint->y) {
				if (!gathering) {
					gathering = true;
					commandQueue.front()->completed = true;
				}
				else {
					gathering = false;
					commandQueue.front()->completed = true;
				}
			}
		}
	}
	
	//Move command
	//TODO: fix pathing
	void move(MoveCommand* command) {
		if (commandQueue.front()->completed) {
			commandQueue.erase(commandQueue.begin());
		}
		else {
			//move x
			if (shape.getPosition().x > command->endPoint->x) {
				setPosition(shape.getPosition().x - speed, shape.getPosition().y);
			}
			else if (shape.getPosition().x < command->endPoint->x) {
				setPosition(shape.getPosition().x + speed, shape.getPosition().y);
			}
			//move y
			if (shape.getPosition().y > command->endPoint->y) {
				setPosition(shape.getPosition().x, shape.getPosition().y - speed);
			}
			else if (shape.getPosition().y < command->endPoint->y) {
				setPosition(shape.getPosition().x, shape.getPosition().y + speed);
			}
			//complete
			if (shape.getPosition().x == command->endPoint->x
				&& shape.getPosition().y == command->endPoint->y) {
				commandQueue.front()->completed = true;
			}
		}
	}
};

//class Unit {
//public:
//	sf::CircleShape shape;
//	std::string name;
//	int id;
//	UnitType type;
//	int maxHealth;
//	int currentHealth;
//	int speed;
//
//	bool isSelected = false;
//	bool isGathering = false;
//	std::vector<Command> commandQueue;
//
//	//constructor
//	Unit() {}
//	Unit(std::string name, int id, UnitType type, int maxHealth, int speed, int circleSize)
//		: name(name), id(id), type(type), maxHealth(maxHealth), currentHealth(maxHealth), speed(speed) {
//		shape.setRadius(circleSize);
//		shape.setFillColor(sf::Color::Green);
//	}
//
//	//set unit position
//	bool setPosition(int x, int y) {
//		shape.setPosition(sf::Vector2f(x, y));
//		return true;
//	}
//
//	//select unit
//	bool select() {
//		if (isSelected) return false;
//		else {
//			isSelected = true;
//			shape.setFillColor(sf::Color::Red);
//			return true;
//		}
//	}
//
//	//deselect unit
//	bool deselect() {
//		if (!isSelected) return false;
//		else {
//			isSelected = false;
//			shape.setFillColor(sf::Color::Green);
//			return true;
//		}
//	}
//
//	//TODO: fix pathing
//	//move command
//	void move(Command& command) {
//		if (command.completed) {
//			commandQueue.erase(commandQueue.begin());
//		}
//		else {
//			//move x
//			if (shape.getPosition().x > command.endPoint.x) {
//				setPosition(shape.getPosition().x - speed, shape.getPosition().y);
//			}
//			else if (shape.getPosition().x < command.endPoint.x) {
//				setPosition(shape.getPosition().x + speed, shape.getPosition().y);
//			}
//			//move y
//			if (shape.getPosition().y > command.endPoint.y) {
//				setPosition(shape.getPosition().x, shape.getPosition().y - speed);
//			}
//			else if (shape.getPosition().y < command.endPoint.y) {
//				setPosition(shape.getPosition().x, shape.getPosition().y + speed);
//			}
//			//complete
//			if (shape.getPosition().x == command.endPoint.x
//				&& shape.getPosition().y == command.endPoint.y) { 
//				command.completed = true;
//			}
//		}
//	}
//
//	//TODO: fix pathing
//	//gather command
//	void gather(Command& command) {
//		if (command.completed) {
//			if (commandQueue.size() > 1) {
//				commandQueue.erase(commandQueue.begin());
//			}
//			else {
//				command.completed = false;
//			}
//		}
//		else {
//			//move x
//			if (shape.getPosition().x > command.endPoint.x) {
//				setPosition(shape.getPosition().x - speed, shape.getPosition().y);
//			}
//			else if (shape.getPosition().x < command.endPoint.x) {
//				setPosition(shape.getPosition().x + speed, shape.getPosition().y);
//			}
//			//move y
//			if (shape.getPosition().y > command.endPoint.y) {
//				setPosition(shape.getPosition().x, shape.getPosition().y - speed);
//			}
//			else if (shape.getPosition().y < command.endPoint.y) {
//				setPosition(shape.getPosition().x, shape.getPosition().y + speed);
//			}
//			if (shape.getPosition().x == command.endPoint.x
//				&& shape.getPosition().y == command.endPoint.y
//				&& !isGathering) {
//				command.startPoint = command.endPoint;
//				command.endPoint = Point(0, 0);
//				isGathering = true;
//				command.completed = true;
//			}
//			else if (shape.getPosition().x == command.endPoint.x
//				&& shape.getPosition().y == command.endPoint.y
//				&& isGathering) {
//				command.endPoint = command.startPoint;
//				isGathering = false;
//			}
//		}
//	}
//};
//
//bool operator==(Unit a, Unit b) {
//	if (a.name == b.name
//		&& a.id == b.id
//		&& a.type == b.type
//		&& a.maxHealth == b.maxHealth
//		&& a.speed == b.speed)
//		return true;
//	else return false;
//}