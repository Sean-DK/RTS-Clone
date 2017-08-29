#include "stdafx.h"
#include "Unit.h"
#include "Resource.h"


int main()
{
	//main window
	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//TEST AREA
	std::vector<Unit> unitList;
	Unit testUnit("circle", UnitType::Worker, 150, 32);
	unitList.push_back(testUnit);
	Unit unitTwo("second", UnitType::Army, 300, 48);
	unitList.push_back(unitTwo);
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
		for (int i = 0; i < unitList.size(); i++) {
			unitList[i].setPosition(i * 150, i * 150);
			window.draw(unitList[i].shape);
		}
		//
		window.display();
	}

	return 0;
}

