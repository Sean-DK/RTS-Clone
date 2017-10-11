#pragma once

#include "stdafx.h"
#include "Controller.h"

//Execute command, wrapper for Unit.execute()
void Controller::executeCommand() {
		//Unit Commands
		for (int i = 0; i < units.size(); i++) {
			units[i]->executeCommand();
		}
		//TODO: structure commands
}

//Draw objects, this is a wrapper for sf::Window::draw
void Controller::draw(sf::RenderWindow* w) {
	w->clear();
	for (int i = 0; i < resources.size(); w->draw(*resources[i++]->getShape()));
	for (int i = 0; i < structures.size(); w->draw(*structures[i++]->getShape()));
	for (int i = 0; i < units.size(); w->draw(*units[i++]->getShape()));
	w->draw(*box);
	w->display();
}

//Create unit
void Controller::createUnit(UnitName n) {
	Unit* newUnit = new Unit(n, currentID++, this);
	units.push_back(newUnit);
}

//Create resources
void Controller::createResource(int a) {
	Resource* newResource = new Resource(a);
	resources.push_back(newResource);
}

//Create structure
//TODO: finish structures
void Controller::createStructure() {}

//Manage control groups
void Controller::manageControlGroup(int n) {
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

//Input event handling
//Left mouse press
void Controller::leftMousePress(Point mousePos) {}

//Right mouse press
void Controller::rightMousePress(Point mousePos) {}

//Left mouse release
void Controller::leftMouseRelease(Point mousePos) {
	switch (cursor.getState()) {
	case (CursorState::A):
		//Attack stuff
		break;
	case (CursorState::N):
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
				//if the unit was NOT clicked
				if (!units[i]->getShape()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					//if shift is NOT held
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						units[i]->deselect();
					}
					//if shift is held
					else {
						//do nothing
					}
				}
				//if the unit was clicked
				else {
					//if shift and control are NOT held down
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
						&& !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
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
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						//if the unit is NOT selected {
						if (!units[i]->isSelected()) {
							units[i]->select();
						}
						//if the unit is selected
						else {
							units[i]->deselect();
						}
					}
					//if control is held down
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
						//select all units of same type
						for (int j = 0; j < units.size(); j++) {
							if (units[i]->getType() == units[j]->getType()) {
								units[j]->select();
							}
						}
						break;
					}
				}
			}
		}
		break;
	case (CursorState::P):
		//check all units
		for (int i = 0; i < units.size(); i++) {
			//if the unit is NOT selected
			if (!units[i]->isSelected()) {
				//do nothing
			}
			//if the unit is selected
			else {
				//if shift is NOT held
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					//replace current command with new one
					PatrolCommand* patrolCommand = new PatrolCommand(units[i]->getShape()->getPosition(), mousePos);
					//if there are no commands, push new command
					if (units[i]->commandEmpty()) {
						units[i]->addCommand(patrolCommand);
					}
					//if there is a command, clear queue and push new command
					else {
						units[i]->setCommand(patrolCommand);
					}
				}
				//if shift is held
				else {
					//add new move command to command queue
					PatrolCommand* gatherCommand = new PatrolCommand(units[i]->getShape()->getPosition(), mousePos);
					units[i]->addCommand(gatherCommand);
				}
			}
		}
		cursor.setState(CursorState::N);
		break;
	}
}

//Right mouse release
void Controller::rightMouseRelease(Point mousePos) {
	//check all units
	//TODO: set up "loaded units" that only handles units on screen
	for (int i = 0; i < units.size(); i++) {
		//if the unit was clicked
		//TODO: figure out attack commands
		//if a unit is right clicked then use list of "selected units" and
		//set the "target" to the clicked unit and pass the attack command
		//to all units in the "selected units" list
		if (units[i]->getShape()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
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
				if (resources[j]->getShape()->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
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

//Mouse drag
void Controller::mouseDrag(Point* mousePos, sf::Event e) {
	Point* currentPos = new Point(e.mouseMove.x - mousePos->x, e.mouseMove.y - mousePos->y);
	box->setSize(sf::Vector2f(currentPos->x, currentPos->y));
	box->setPosition(mousePos->x, mousePos->y);
	box->setOutlineColor(sf::Color::Green);
	box->setOutlineThickness(2);
	box->setFillColor(sf::Color::Transparent);
}

//Keyboard key press
void Controller::keyPress(sf::Keyboard::Key k) {
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
	case (sf::Keyboard::P):
		cursor.setState(CursorState::P);
		break;
	}
}

//Keyboard key release
void Controller::keyRelease(sf::Keyboard::Key k) {}

//Event Handler
//TODO: use switch here
void Controller::eventHandler(sf::Event e, sf::RenderWindow* w) {
	static Point mousePos(0, 0);
	if (e.type == sf::Event::Resized) {
		w->setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
	}
	if (e.type == sf::Event::MouseButtonPressed) {
		//grab mouse position
		mousePos.x = sf::Mouse::getPosition(*w).x;
		mousePos.y = sf::Mouse::getPosition(*w).y;
		//switch based on which key was pressed
		switch (e.key.code) {
		case sf::Mouse::Left:
			leftMousePress(mousePos);
			break;
		case sf::Mouse::Right:
			rightMousePress(mousePos);
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
			leftMouseRelease(mousePos);
			break;
		case sf::Mouse::Right:
			rightMouseRelease(mousePos);
			break;
		}
	}
	//Mouse is dragged while holding left button
	else if (cursor.getState() == CursorState::N
		&& e.type == sf::Event::MouseMoved 
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
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
void Controller::initialize() {
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	units[0]->setPosition(50, 50);
	units[1]->setPosition(100, 50);
	units[2]->setPosition(50, 100);
	units[3]->setPosition(100, 100);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	units[4]->setPosition(200, 100);
	units[5]->setPosition(250, 100);
	units[6]->setPosition(200, 150);
	units[7]->setPosition(250, 150);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	units[8]->setPosition(500, 300);
	units[9]->setPosition(550, 300);
	units[10]->setPosition(500, 350);
	units[11]->setPosition(550, 350);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	createUnit(UnitName::SCV);
	units[12]->setPosition(50, 400);
	units[13]->setPosition(75, 550);
	units[14]->setPosition(375, 75);
	units[15]->setPosition(125, 300);

	createResource(500);
	resources[0]->setPosition(300, 500);
}