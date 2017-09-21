#include "stdafx.h"
#include "Controller.h"
#include <iostream>

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(768, 640), "Window");
	window->setFramerateLimit(60);

	//Controller
	Controller* controller = new Controller();
	controller->initialize();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event)) { 
			controller->eventHandler(event, window);
		}

		//execute commands
		controller->executeCommand();

		//draw
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