#include "stdafx.h"
#include "Controller.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	window.setFramerateLimit(60);

	//Controller
	Controller* controller = new Controller();

	controller->createUnit(UnitName::SCV);
	controller->createUnit(UnitName::SCV);
	controller->units[1]->setPosition(100, 100);
	controller->createUnit(UnitName::Marine);
	controller->units[2]->setPosition(300, 100);

	controller->createResource(500);
	controller->resources[0]->setPosition(300, 500);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				//grab mouse position
				Point* mousePos = new Point(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				switch (event.key.code) {
				case sf::Mouse::Left:
					controller->LeftMousePress(mousePos);
					break;
				case sf::Mouse::Right:
					controller->RightMousePress(mousePos);
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
					for (int i = 0; i < controller->units.size(); i++) {
						//if the unit was clicked
						if (controller->units[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
							//if shift is NOT held down
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								//if the unit is NOT selected
								if (!controller->units[i]->isSelected()) {
									controller->units[i]->select();
								}
								//if the unit is selected
								else {
									//do nothing
								}
							}
							//if shift is held down
							else {
								//if the unit is NOT selected {
								if (!controller->units[i]->isSelected()) {
									controller->units[i]->select();
								}
								//if the unit is selected
								else {
									controller->units[i]->deselect();
								}
							}
						}
						//if the unit was NOT clicked
						else {
							//if shift is NOT held
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								controller->units[i]->deselect();
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
					for (int i = 0; i < controller->units.size(); i++) {
						//if the unit was clicked
						//TODO: figure out attack commands
						//if a unit is right clicked then use list of "selected units" and
						//set the "target" to the clicked unit and pass the attack command
						//to all units in the "selected units" list
						if (controller->units[i]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
							//if shift is NOT held down
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
								//if the unit is NOT selected
								if (!controller->units[i]->isSelected()) {
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
								if (!controller->units[i]->isSelected()) {
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
							for (int j = 0; j < controller->resources.size(); j++) {
								//if the node was clicked
								if (controller->resources[j]->getShape()->getGlobalBounds().contains(mousePos->x, mousePos->y)) {
									//check for selected units
									for (int k = 0; k < controller->units.size(); k++) {
										//if the unit is NOT selected
										if (!controller->units[k]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//if shift is NOT held
											if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
												//replace current command with new one
												GatherCommand* gatherCommand = new GatherCommand(controller->resources[j]);
												//if there are no commands, push new command
												if (controller->units[k]->commandEmpty()) {
													controller->units[k]->addCommand(gatherCommand);
												}
												//if there is a command, clear queue and push new command
												else {
													controller->units[k]->setCommand(gatherCommand);
												}
											}
											//if shift is held
											else {
												//add new move command to command queue
												GatherCommand* gatherCommand = new GatherCommand(controller->resources[j]);
												controller->units[k]->addCommand(gatherCommand);
											}
										}
									}
								}
								//if the node was NOT clicked
								else {
									//if shift is NOT held
									if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
										//if the unit is NOT selected
										if (!controller->units[i]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//replace current move command with new one
											MoveCommand* moveCommand = new MoveCommand(mousePos);
											//if there are no commands, push new command
											if (controller->units[i]->commandEmpty()) {
												controller->units[i]->addCommand(moveCommand);
											}
											//if there is a command, clear queue and push new command
											else {
												controller->units[i]->setCommand(moveCommand);
											}
										}
									}
									//if shift is held
									else {
										//if the unit is NOT selected
										if (!controller->units[i]->isSelected()) {
											//do nothing
										}
										//if the unit is selected
										else {
											//add new move command to command queue
											MoveCommand* moveCommand = new MoveCommand(mousePos);
											controller->units[i]->addCommand(moveCommand);
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
				controller->KeyPress(event.key.code);
			}
			else if (event.type == sf::Event::KeyReleased) {
				controller->KeyRelease(event.key.code);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//execute commands
		//TODO: add structure command execution
		for (int i = 0; i < controller->units.size(); i++) {
			controller->units[i]->executeCommand();
		}

		window.clear();
		//draw resources
		//TODO: only draw resources that will be on screen
		for (int i = 0; i < controller->resources.size(); i++) {
			window.draw(*controller->resources[i]->getShape());
		}
		//draw structures
		//TODO: only draw structures that will be on screen

		//draw units
		//TODO: only draw units that will be on screen
		for (int i = 0; i < controller->units.size(); i++) {
			window.draw(*controller->units[i]->getShape());
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