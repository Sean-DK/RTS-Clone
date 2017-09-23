//TODO: move pretty much all functionality into the controller
//e.g. unit selection and deselection, etc.

//TODO: deal with memory leaks, there's a lot

#pragma once

#include <vector>
#include "Unit.h"
#include "Resource.h"
#include "Structure.h"
#include "Command.h"

enum UnitName;
class Unit;
class Point;
class Command;
class AttackCommand;
class GatherCommand;
class MoveCommand;

class Controller {
private:
	std::vector<Unit*> units;
	std::vector<Resource*> resources;
	std::vector<Structure*> structures;
	std::vector<Unit*> controlGroups[10];
	sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(0, 0));
	int currentID = 0;

public:
	//Getters
	int getUnitSize() { return units.size(); }
	int getResourceSize() { return resources.size(); }
	int getStructureSize() { return structures.size(); }
	std::vector<Unit*> getUnits() { return units; }

	//Execute Commands
	void executeCommand();

	//Draw Objects
	void draw(sf::RenderWindow*);

	//Create Unit
	void createUnit(UnitName);

	//Create Resource
	void createResource(int);

	//Create Structure
	//TODO: finish structure
	void createStructure();
	
	//Add Control Group
	void manageControlGroup(int);

	//Input Event Handling
	void leftMousePress(Point*);
	void rightMousePress(Point*);
	void leftMouseRelease(Point*);
	void rightMouseRelease(Point*);
	void mouseDrag(Point*, sf::Event);
	void keyPress(sf::Keyboard::Key);
	void keyRelease(sf::Keyboard::Key);

	//Event Handler
	//TODO: use switch here
	void eventHandler(sf::Event, sf::RenderWindow*);

	//Initialize
	void initialize();
};