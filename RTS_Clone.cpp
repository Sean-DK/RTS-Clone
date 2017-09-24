#include "stdafx.h"
#include "Controller.h"
#include <iostream>

int main()
{
	//Create render window
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(768, 640), "Window");
	//Set frame limit, THIS AFFECTS HOW FAST UNITS MOVE WITH Unit.speed
	window->setFramerateLimit(60);

	//Create controller, this does everything
	Controller* controller = new Controller();
	//Initialize, move this to the constructor of Controller so it happens automatically
	controller->initialize();

	while (window->isOpen())
	{
		//Poll for events
		sf::Event event;
		while (window->pollEvent(event)) {
			controller->eventHandler(event, window);
		}

		//Execute commands
		controller->executeCommand();

		//Draw
		controller->draw(window);	
	}

	return 0;
}

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