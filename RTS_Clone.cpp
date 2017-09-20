#include "stdafx.h"
#include "Unit.h"
#include "Command.h"
#include "Resource.h"

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	window.setFramerateLimit(60);

	std::vector<Unit*> unitList;
	Unit* unitOne = new Unit(UnitName::SCV);
	unitList.push_back(unitOne);
	Unit* unitTwo = new Unit(UnitName::SCV);
	unitList.push_back(unitTwo);
	unitList[1]->setPosition(Point(100, 100));
	Unit* unitThree = new Unit(UnitName::Marine);
	unitList.push_back(unitThree);
	unitList[2]->setPosition(Point(300, 100));

	std::vector<Resource*> resourceList;
	Resource* resourceOne = new Resource(500);
	resourceOne->shape.setPosition(sf::Vector2f(300, 500));
	resourceList.push_back(resourceOne);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				//grab mouse position
				Point mousePos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				switch (event.key.code) {
				case sf::Mouse::Left:
					//left click stuff
					break;
				case sf::Mouse::Right:
					//right click stuff
					break;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased) {
				//grab mouse position
				Point* mousePos = new Point(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				//switch based on which key was pressed
				switch (event.key.code) {
				case sf::Mouse::Left:
					//check all units
					//TODO: set up "loaded units" that only handles units on screen
					for (int i = 0; i < unitList.size(); i++) {
						//if the unit was clicked
						if (unitList[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
							//if shift is NOT held down
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								//if the unit is NOT selected
								if (!unitList[i]->isSelected()) {
									unitList[i]->select();
								}
								//if the unit is selected
								else {
									//do nothing
								}
							}
							//if shift is held down
							else {
								//if the unit is NOT selected {
								if (!unitList[i]->isSelected()) {
									unitList[i]->select();
								}
								//if the unit is selected
								else {
									unitList[i]->deselect();
								}
							}
						}
						//if the unit was NOT clicked
						else {
							//if shift is NOT held
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								unitList[i]->deselect();
							}
							//if shift is held
							else {
								//do nothing
							}
						}
					}
					break;
				case sf::Mouse::Right:
					//check all units
					//TODO: set up "loaded units" that only handles units on screen
					for (int i = 0; i < unitList.size(); i++) {
						//if the unit was clicked
						//TODO: figure out attack commands
						//if a unit is right clicked then use list of "selected units" and
						//set the "target" to the clicked unit and pass the attack command
						//to all units in the "selected units" list
						if (unitList[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
							//if shift is NOT held down
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								//if the unit is NOT selected
								if (!unitList[i]->isSelected()) {
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
								if (!unitList[i]->isSelected()) {
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
							for (int j = 0; j < resourceList.size(); j++) {
								//if the node was clicked
								if (resourceList[j]->shape.getGlobalBounds().contains(mousePos->x, mousePos->y)) {
									//check for selected units
									for (int k = 0; k < unitList.size(); k++) {
										//if the unit is NOT selected
										if (!unitList[k]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//if shift is NOT held
											if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
												//replace current command with new one
												GatherCommand* gatherCommand = new GatherCommand(resourceList[j]);
												//if there are no commands, push new command
												if (unitList[k]->commandEmpty()) {
													unitList[k]->addCommand(gatherCommand);
												}
												//if there is a command, clear queue and push new command
												else {
													unitList[k]->setCommand(gatherCommand);
												}
											}
											//if shift is held
											else {
												//add new move command to command queue
												GatherCommand* gatherCommand = new GatherCommand(resourceList[j]);
												unitList[k]->addCommand(gatherCommand);
											}
										}
									}
								}
								//if the node was NOT clicked
								else {
									//if shift is NOT held
									if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
										//if the unit is NOT selected
										if (!unitList[i]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//replace current move command with new one
											MoveCommand* moveCommand = new MoveCommand(mousePos);
											//if there are no commands, push new command
											if (unitList[i]->commandEmpty()) {
												unitList[i]->addCommand(moveCommand);
											}
											//if there is a command, clear queue and push new command
											else {
												unitList[i]->setCommand(moveCommand);
											}
										}
									}
									//if shift is held
									else {
										//if the unit is NOT selected
										if (!unitList[i]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//add new move command to command queue
											MoveCommand* moveCommand = new MoveCommand(mousePos);
											unitList[i]->addCommand(moveCommand);
										}
									}
								}
							}
						}
					}
					break;
				}
			}
			else if (event.type == sf::Event::KeyPressed) {
				//key presses
			}
			else if (event.type == sf::Event::KeyReleased) {
				//key releases
			}
			//////////////////////////////////////
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//execute commands
		for (int i = 0; i < unitList.size(); i++) {
			unitList[i]->executeCommand();
		}

		window.clear();
		//draw units
		//TODO: only draw units that will be on screen
		for (int i = 0; i < unitList.size(); i++) {
			window.draw(*unitList[i]->getShape());
		}
		//draw resources
		//TODO: only draw resources that will be on screen
		for (int i = 0; i < resourceList.size(); i++) {
			window.draw(resourceList[i]->shape);
		}
		window.display();
	}

	return 0;
}

//TODO: CHANGE HOW COMMANDS ARE CREATED AND MANAGED.
//Allow main() to pass sf::Events to the unit and manage commands in Unit.h
//Use switches instead of Ifs

//TODO: Try to find a way for the mouse to check if it's clicking a unit, rather than
//having each unit check if it was clicked by the mouse

//Test block
//{
//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
//
//	//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//		}
//
//		window.clear();
//		//draw
//		window.display();
//	}
//}
//End test block