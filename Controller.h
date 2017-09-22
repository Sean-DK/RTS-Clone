//TODO: move pretty much all functionality into the controller
//e.g. unit selection and deselection, etc.

//TODO: deal with memory leaks, there's a lot

#pragma once

#include <vector>
#include "Unit.h"
#include "Resource.h"
#include "Structure.h"
#include "Command.h"

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

	//Execute Commands
	void executeCommand() {
		//Unit Commands
		for (int i = 0; i < units.size(); i++) {
			units[i]->executeCommand();
		}
		//TODO: structure commands
	}

	//Draw Objects
	void draw(sf::RenderWindow* w) {
		w->clear();
		for (int i = 0; i < resources.size(); w->draw(*resources[i++]->getShape()));
		for (int i = 0; i < structures.size(); w->draw(*structures[i++]->getShape()));
		for (int i = 0; i < units.size(); w->draw(*units[i++]->getShape()));
		w->draw(*box);
		w->display();
	}

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
	
	//Add Control Group
	void manageControlGroup(int n) {
		//if shift is NOT held
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			//if the control group is NOT empty
			if (!controlGroups[n].empty()) {
				//deselect all units
				for (int i = 0; i < units.size(); i++) {
					units[i]->deselect();
				}
				//select units in control group n
				for (int i = 0; i < controlGroups[n].size(); i++) {
					controlGroups[n][i]->select();
				}
			}
			//if the control group is empty
			else {
				//do nothing
			}
		}
		//if shift is held
		else {
			//clear control group n
			controlGroups[n].clear();
			//push selected units into control group n
			for (int i = 0; i < units.size(); i++) {
				if (units[i]->isSelected()) {
					controlGroups[n].push_back(units[i]);
				}
			}
		}
	}

	//Input Event Handling
	void LeftMousePress(Point* mousePos) {}
	void RightMousePress(Point* mousePos) {}
	void LeftMouseRelease(Point* mousePos) {
		//if there is a box
		if (box->getSize() != sf::Vector2f(0, 0)) {
			//check all units
			//TODO: set up "loaded units" that only handles units on screen
			for (int i = 0; i < units.size(); i++) {
				//if a unit is in the box
				if (box->getGlobalBounds().intersects(units[i]->getShape()->getGlobalBounds())) {
					//if shift is NOT held
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						units[i]->select();
					}
					//if shift is held
					else {
						//if the unit is selected
						if (units[i]->isSelected()) {
							units[i]->deselect();
						}
						//if the unit is NOT selected
						else {
							units[i]->select();
						}
					}
				}
				//if a unit is NOT in a box and shift is held
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					//do nothing
				}
				//if a unit is NOT in a box and shift is NOT held
				else {
					units[i]->deselect();
				}
			}
			//delete the box
			box->setSize(sf::Vector2f(0, 0));
		}
		//if there is NOT a box
		else {
			//check all units
			//TODO: set up "loaded units" that only handles units on screen
			for (int i = 0; i < units.size(); i++) {
				//if the unit was clicked
				if (units[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
					//if shift is NOT held down
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						//if the unit is NOT selected
						if (!units[i]->isSelected()) {
							units[i]->select();
						}
						//if the unit is selected
						else {
							//do nothing
						}
					}
					//if shift is held down
					else {
						//if the unit is NOT selected {
						if (!units[i]->isSelected()) {
							units[i]->select();
						}
						//if the unit is selected
						else {
							units[i]->deselect();
						}
					}
				}
				//if the unit was NOT clicked
				else {
					//if shift is NOT held
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						units[i]->deselect();
					}
					//if shift is held
					else {
						//do nothing
					}
				}
			}
		}
	}

	void RightMouseRelease(Point* mousePos) {
		//check all units
		//TODO: set up "loaded units" that only handles units on screen
		for (int i = 0; i < units.size(); i++) {
			//if the unit was clicked
			//TODO: figure out attack commands
			//if a unit is right clicked then use list of "selected units" and
			//set the "target" to the clicked unit and pass the attack command
			//to all units in the "selected units" list
			if (units[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
				//if shift is NOT held down
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					//if the unit is NOT selected
					if (!units[i]->isSelected()) {
						//do nothing
					}
					//if the unit is selected
					else {
						//do nothing
					}
				}
				//if shift is held down
				else {
					//if the unit is NOT selected {
					if (!units[i]->isSelected()) {
						//do nothing
					}
					//if the unit is selected
					else {
						//do nothing
					}
				}
			}
			//if the unit was NOT clicked
			else {
				//check to see if a resource was clicked
				for (int j = 0; j < resources.size(); j++) {
					//if the node was clicked
					if (resources[j]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
						//check for selected units
						for (int k = 0; k < units.size(); k++) {
							//if the unit is NOT selected
							if (!units[k]->isSelected()) {
								//do nothing
							}
							//if the unit is selected
							else {
								//if shift is NOT held
								if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
									//replace current command with new one
									GatherCommand* gatherCommand = new GatherCommand(resources[j]);
									//if there are no commands, push new command
									if (units[k]->commandEmpty()) {
										units[k]->addCommand(gatherCommand);
									}
									//if there is a command, clear queue and push new command
									else {
										units[k]->setCommand(gatherCommand);
									}
								}
								//if shift is held
								else {
									//add new move command to command queue
									GatherCommand* gatherCommand = new GatherCommand(resources[j]);
									units[k]->addCommand(gatherCommand);
								}
							}
						}
					}
					//if the node was NOT clicked
					else {
						//if shift is NOT held
						if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
							//if the unit is NOT selected
							if (!units[i]->isSelected()) {
								//do nothing
							}
							//if the unit is selected
							else {
								//replace current move command with new one
								MoveCommand* moveCommand = new MoveCommand(mousePos);
								//if there are no commands, push new command
								if (units[i]->commandEmpty()) {
									units[i]->addCommand(moveCommand);
								}
								//if there is a command, clear queue and push new command
								else {
									units[i]->setCommand(moveCommand);
								}
							}
						}
						//if shift is held
						else {
							//if the unit is NOT selected
							if (!units[i]->isSelected()) {
								//do nothing
							}
							//if the unit is selected
							else {
								//add new move command to command queue
								MoveCommand* moveCommand = new MoveCommand(mousePos);
								units[i]->addCommand(moveCommand);
							}
						}
					}
				}
			}
		}
	}

	void mouseDrag(Point* mousePos, sf::Event e) {
		Point* currentPos = new Point(e.mouseMove.x - mousePos->x, e.mouseMove.y - mousePos->y);
		box->setSize(sf::Vector2f(currentPos->x, currentPos->y));
		box->setPosition(mousePos->x, mousePos->y);
		box->setOutlineColor(sf::Color::Green);
		box->setOutlineThickness(2);
		box->setFillColor(sf::Color::Transparent);
	}

	void keyPress(sf::Keyboard::Key k) {
		switch (k) {
		case (sf::Keyboard::Num1):
			manageControlGroup(1);
			break;
		case (sf::Keyboard::Num2):
			manageControlGroup(2);
			break;
		case (sf::Keyboard::Num3):
			manageControlGroup(3);
			break;
		case (sf::Keyboard::Num4):
			manageControlGroup(4);
			break;
		case (sf::Keyboard::Num5):
			manageControlGroup(5);
			break;
		case (sf::Keyboard::Num6):
			manageControlGroup(6);
			break;
		case (sf::Keyboard::Num7):
			manageControlGroup(7);
			break;
		case (sf::Keyboard::Num8):
			manageControlGroup(8);
			break;
		case (sf::Keyboard::Num9):
			manageControlGroup(9);
			break;
		case (sf::Keyboard::Num0):
			manageControlGroup(0);
			break;
		}
	}

	void keyRelease(sf::Keyboard::Key k) {}

	//Event Handler
	//TODO: use switch here
	void eventHandler(sf::Event e, sf::RenderWindow* w) {
		static Point mousePos(0, 0);
		if (e.type == sf::Event::MouseButtonPressed) {
			//grab mouse position
			mousePos.x = sf::Mouse::getPosition(*w).x;
			mousePos.y = sf::Mouse::getPosition(*w).y;
			//switch based on which key was pressed
			switch (e.key.code) {
			case sf::Mouse::Left:
				LeftMousePress(&mousePos);
				break;
			case sf::Mouse::Right:
				RightMousePress(&mousePos);
				break;
			}
		}
		else if (e.type == sf::Event::MouseButtonReleased) {
			//grab mouse position
			mousePos.x = sf::Mouse::getPosition(*w).x;
			mousePos.y = sf::Mouse::getPosition(*w).y;
			//switch based on which key was pressed
			switch (e.key.code) {
			case sf::Mouse::Left:
				LeftMouseRelease(&mousePos);
				break;
			case sf::Mouse::Right:
				RightMouseRelease(&mousePos);
				break;
			}
		}
		//Mouse is dragged while holding left button
		else if (e.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mouseDrag(&mousePos, e);
		}
		else if (e.type == sf::Event::KeyPressed) {
			keyPress(e.key.code);
		}
		else if (e.type == sf::Event::KeyReleased) {
			keyRelease(e.key.code);
		}
		if (e.type == sf::Event::Closed) {
			w->close();
		}
	}

	//Initialize
	void initialize() {
		createUnit(UnitName::SCV);
		units[0]->setPosition(400, 50);
		createUnit(UnitName::SCV);
		units[1]->setPosition(100, 100);
		createUnit(UnitName::Marine);
		units[2]->setPosition(300, 100);

		createResource(500);
		resources[0]->setPosition(300, 500);
	}
};