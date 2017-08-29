#include "stdafx.h"
#include "Unit.h"
#include "Resource.h"

#include <iostream>

int main()
{

 	//Test block
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");


		//

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			//draw
			window.display();
		}
	}
	//End test block

	//Test block
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");


		//

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			//draw
			window.display();
		}
	}
	//End test block

	return 0;
}

