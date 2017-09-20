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

	void createUnit(UnitName n) {
		Unit* newUnit = new Unit(n, currentID++);
		units.push_back(newUnit);
	}
	void createResource(int a) {
		Resource* newResource = new Resource(a);
		resources.push_back(newResource);
	}
	//TODO: finish structure
	void createStructure() {}

};