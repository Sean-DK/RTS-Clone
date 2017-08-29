#include "stdafx.h"
#include <Windows.h>
#include "Unit.h"
#include "Resource.h"


int main()
{
	//main window
	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");


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

	return 0;
}

