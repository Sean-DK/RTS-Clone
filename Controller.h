//TODO: move pretty much all functionality into the controller
//e.g. unit selection and deselection, etc.

//TODO: deal with memory leaks, there's a lot

#pragma once

#include <vector>
#include "Unit.h"
#include "Resource.h"
#include "Structure.h"
#include "Command.h"
#include "Cursor.h"

//Forward declarations
enum UnitName;
class Unit;
class Point;
class Command;
class AttackCommand;
class GatherCommand;
class MoveCommand;
class PatrolCommand;
class Cursor;
class Structure;

//Controller
class Controller {
private:
	Cursor cursor;
	std::vector<Unit*> units;
	std::vector<Resource*> resources;
	std::vector<Structure*> structures;
	std::vector<Unit*> controlGroups[10];
	sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(0, 0));
	int currentID = 0;

public:
	//Accessors
	int getUnitSize() { return units.size(); }
	int getResourceSize() { return resources.size(); }
	int getStructureSize() { return structures.size(); }
	std::vector<Unit*> getUnits() { return units; }


	//Execute command, wrapper for Unit.execute()
	void executeCommand();

	//Draw objects, this is a wrapper for sf::Window::draw
	void draw(sf::RenderWindow*);

	//Create unit
	void createUnit(UnitName);

	//Create resource
	void createResource(int);

	//Create structure
	//TODO: finish structure
	void createStructure();
	
	//Manage control groups
	void manageControlGroup(int);

	//Input event handling
	void leftMousePress(Point);
	void rightMousePress(Point);
	void leftMouseRelease(Point);
	void rightMouseRelease(Point);
	void mouseDrag(Point*, sf::Event);
	void keyPress(sf::Keyboard::Key);
	void keyRelease(sf::Keyboard::Key);

	//Event handler, merely calls the above functions
	//TODO: use switch here, maybe??
	void eventHandler(sf::Event, sf::RenderWindow*);

	//Initialize, does required actions at start-up
	void initialize();
};