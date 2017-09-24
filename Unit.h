#pragma once

#include <vector>
#include "Point.h"
#include "Command.h"
#include "Controller.h"
#include "UnitCommand.h"

#include <iostream>

//Forward declarations
class Controller;
class Point;

//UnitType
enum UnitType {
	Worker,
	Army
};

//UnitName
enum UnitName {
	SCV,
	Marine,
	Medic,
	Tank,
};

//Unit
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
	//Constructors
	Unit() {}
	Unit(UnitName, int, Controller*);

	//Overloads
	bool operator==(Unit*);

	//Accessors
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

	//Mutators
	void setPosition(Point* p) { shape.setPosition(p->x, p->y); }
	void setPosition(float x, float y) { shape.setPosition(x, y); }
	void setHealth(int h) { currentHealth = h; }
	void select();
	void deselect();	
	void setCommand(Command*);
	void addCommand(Command* c) { commandQueue.push_back(c); }

	//Command engine
	void executeCommand();

	//Attack command
	void attack(AttackCommand*);

	//Gather command
	//TODO: fix pathing and timing
	//TODO: when giving "Gather" command and holding shift the unit walks offscreen and is lost
	void gather(GatherCommand*);
	
	//Move command
	//TODO: fix pathing
	void move(MoveCommand*);
};