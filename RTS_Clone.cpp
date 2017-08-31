#include "stdafx.h"
#include "Unit.h"
#include "Command.h"
#include "Resource.h"

#include <iostream>

int main()
{

	/*

 	//Create unit
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);

		if (unitList[0] == unitOne) std::cout << "1 PASS\n";
		else std::cout << "1 FAIL\n";

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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Set unit position
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);
		unitList[0].setPosition(300, 300);

		if (unitList[0].shape.getPosition().x == 300
			&& unitList[0].shape.getPosition().y == 300) std::cout << "2 PASS\n";
		else std::cout << "2 FAIL\n";

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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Select an unselected unit
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);
		

		if (unitList[0].select()) std::cout << "3 PASS\n";
		else std::cout << "3 FAIL\n";

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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Select an already selected unit
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);
		unitList[0].select();

		if (!(unitList[0].select())) std::cout << "4 PASS\n";
		else std::cout << "4 FAIL\n";


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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Deselect a selected unit
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);
		unitOne.select();

		if (unitOne.deselect()) std::cout << "5 PASS\n";
		else std::cout << "5 FAIL\n";

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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Deselect an unselected unit
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);

		if (!(unitOne.deselect())) std::cout << "6 PASS\n";
		else std::cout << "6 FAIL\n";

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
			window.draw(unitList[0].shape);
			window.display();
		}
	}
	//End test block

	//Move a unit with a command
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
		window.setFramerateLimit(60);

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);

		Command commandOne(CommandType::Move, Point(500, 500));
		unitList[0].commandQueue.push_back(commandOne);


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			//execute commands
			for (int i = 0; i < unitList.size(); i++) {
				//if there is a command in the queue
				if (!(unitList[i].commandQueue.empty())) {
					//if that command is a Move command
					if (unitList[i].commandQueue[0].type == CommandType::Move) {
						if (unitList[i].move(unitList[i].commandQueue[0])) {
							unitList[i].commandQueue.erase(unitList[i].commandQueue.begin());
						}
					}
				}
			}

			window.clear();
			window.draw(unitList[0].shape);
			window.display();
		}

		if (unitList[0].commandQueue.empty()) std::cout << "7 PASS\n";
		else std::cout << "7 FAIL\n";
	}
	//End test block

	
	*/

	//Queue two move commands
	{
		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
		window.setFramerateLimit(60);

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
		unitList.push_back(unitOne);

		Command commandOne(CommandType::Move, Point(500, 500));
		unitList[0].commandQueue.push_back(commandOne);
		Command commandTwo(CommandType::Move, Point(700, 200));
		unitList[0].commandQueue.push_back(commandTwo);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			//execute commands
			for (int i = 0; i < unitList.size(); i++) {
				//if there is a command in the queue
				if (!(unitList[i].commandQueue.empty())) {
					//if that command is a Move command
					if (unitList[i].commandQueue[0].type == CommandType::Move) {
						if (unitList[i].move(unitList[i].commandQueue[0])) {
							unitList[i].commandQueue.erase(unitList[i].commandQueue.begin());
						}
					}
				}
			}

			window.clear();
			window.draw(unitList[0].shape);
			window.display();
		}


		if (unitList[0].commandQueue.empty()) std::cout << "8 PASS\n";
		else std::cout << "8 FAIL\n";
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