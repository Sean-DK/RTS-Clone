#pragma once

#include <vector>
#include "Unit.h"
#include "Resource.h"
#include "Structure.h"
#include "Command.h"

class Controller {
private:
	int currentID = 0;
public:
	std::vector<Unit*> units;
	std::vector<Resource*> resources;
	std::vector<Structure*> structures;

	//Create Unit
	void createUnit(UnitName n) {
		Unit* newUnit = new Unit(n, currentID++);
		units.push_back(newUnit);
	}
	//Create Resource
	void createResource(int a) {
		Resource* newResource = new Resource(a);
		resources.push_back(newResource);
	}
	//Create Structure
	//TODO: finish structure
	void createStructure() {}

	//Input Event Handling
	void LeftMousePress(Point* mousePos) {}
	void RightMousePress(Point* mousePos) {}
	void LeftMouseRelease(Point* mousePos) {}
	void RightMouseRelease(Point* mousePos) {}
	void KeyPress(sf::Keyboard::Key k) {}
	void KeyRelease(sf::Keyboard::Key k) {}



};