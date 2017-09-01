#include "stdafx.h"
#include "Unit.h"
#include "Command.h"
#include "Resource.h"

#include <iostream>

int main()
{

 //	//Create unit
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	if (unitList[0] == unitOne) std::cout << "1 PASS\n";
	//	else std::cout << "1 FAIL\n";

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Set unit position
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);
	//	unitList[0].setPosition(300, 300);

	//	if (unitList[0].shape.getPosition().x == 300
	//		&& unitList[0].shape.getPosition().y == 300) std::cout << "2 PASS\n";
	//	else std::cout << "2 FAIL\n";

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Select an unselected unit
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);
	//	

	//	if (unitList[0].select()) std::cout << "3 PASS\n";
	//	else std::cout << "3 FAIL\n";

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Select an already selected unit
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);
	//	unitList[0].select();

	//	if (!(unitList[0].select())) std::cout << "4 PASS\n";
	//	else std::cout << "4 FAIL\n";


	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Deselect a selected unit
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);
	//	unitOne.select();

	//	if (unitOne.deselect()) std::cout << "5 PASS\n";
	//	else std::cout << "5 FAIL\n";

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Deselect an unselected unit
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	if (!(unitOne.deselect())) std::cout << "6 PASS\n";
	//	else std::cout << "6 FAIL\n";

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Move a unit with a command
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	//	window.setFramerateLimit(60);

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	Command commandOne(CommandType::Move, Point(500, 500));
	//	unitList[0].commandQueue.push_back(commandOne);


	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		//execute commands
	//		for (int i = 0; i < unitList.size(); i++) {
	//			//if there is a command in the queue
	//			if (!(unitList[i].commandQueue.empty())) {
	//				//if that command is a Move command
	//				if (unitList[i].commandQueue[0].type == CommandType::Move) {
	//					unitList[i].move(unitList[i].commandQueue[0]);
	//				}
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}

	//	if (unitList[0].commandQueue.empty()) std::cout << "7 PASS\n";
	//	else std::cout << "7 FAIL\n";
	//}
	////End test block

	////Queue two move commands
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	//	window.setFramerateLimit(60);

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	Command commandOne(CommandType::Move, Point(500, 250));
	//	unitList[0].commandQueue.push_back(commandOne);
	//	Command commandTwo(CommandType::Move, Point(700, 200));
	//	unitList[0].commandQueue.push_back(commandTwo);

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		//execute commands
	//		for (int i = 0; i < unitList.size(); i++) {
	//			//if there is a command in the queue
	//			if (!(unitList[i].commandQueue.empty())) {
	//				//if that command is a Move command
	//				if (unitList[i].commandQueue[0].type == CommandType::Move) {
	//					unitList[i].move(unitList[i].commandQueue[0]);
	//				}
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}


	//	if (unitList[0].commandQueue.empty()) std::cout << "8 PASS\n";
	//	else std::cout << "8 FAIL\n";
	//}
	////End test block

	////Gather command
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	//	window.setFramerateLimit(60);

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	Command commandOne(CommandType::Gather, Point(500, 250));
	//	unitList[0].commandQueue.push_back(commandOne);

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		//execute commands
	//		for (int i = 0; i < unitList.size(); i++) {
	//			//if there is a command in the queue
	//			if (!(unitList[i].commandQueue.empty())) {
	//				//if that command is a Move command
	//				if (unitList[i].commandQueue[0].type == CommandType::Move) {
	//					unitList[i].move(unitList[i].commandQueue[0]);
	//				}
	//				else if (unitList[i].commandQueue[0].type == CommandType::Gather) {
	//					unitList[i].gather(unitList[i].commandQueue[0]);
	//				}
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	////Gather command followed a move command
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	//	window.setFramerateLimit(60);

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 5, 32);
	//	unitList.push_back(unitOne);

	//	Command commandOne(CommandType::Gather, Point(500, 250));
	//	unitList[0].commandQueue.push_back(commandOne);
	//	Command commandTwo(CommandType::Move, Point(700, 400));
	//	unitList[0].commandQueue.push_back(commandTwo);

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		//execute commands
	//		for (int i = 0; i < unitList.size(); i++) {
	//			//if there is a command in the queue
	//			if (!(unitList[i].commandQueue.empty())) {
	//				//if that command is a Move command
	//				if (unitList[i].commandQueue[0].type == CommandType::Move) {
	//					unitList[i].move(unitList[i].commandQueue[0]);
	//				}
	//				else if (unitList[i].commandQueue[0].type == CommandType::Gather) {
	//					unitList[i].gather(unitList[i].commandQueue[0]);
	//				}
	//			}
	//		}

	//		window.clear();
	//		window.draw(unitList[0].shape);
	//		window.display();
	//	}
	//}
	////End test block

	//Select unit with mouse click
	//{
	//	sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
	//	window.setFramerateLimit(60);

	//	std::vector<Unit> unitList;
	//	Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 1, 32);
	//	unitList.push_back(unitOne);
	//	Unit unitTwo("Worker Unit", unitList.size(), UnitType::Worker, 50, 1, 32);
	//	unitList.push_back(unitTwo);
	//	unitList[1].setPosition(100, 100);
	//	Unit unitThree("Army Unit", unitList.size(), UnitType::Army, 50, 1, 48);
	//	unitList.push_back(unitThree);
	//	unitList[2].setPosition(300, 100);

	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			//////////////////////////////////////////
	//			if (event.type == sf::Event::MouseButtonReleased) {
	//				sf::Vector2f mousePosVector = sf::Vector2f(sf::Mouse::getPosition(window));
	//				Point mousePosPoint(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	//				if (event.key.code == sf::Mouse::Left) {
	//					for (int i = 0; i < unitList.size(); i++) {
	//						if (unitList[i].shape.getGlobalBounds().contains(mousePosVector)) {
	//							unitList[i].select();
	//						}
	//						else {
	//							unitList[i].deselect();
	//						}
	//					}
	//				}
	//				else if (event.key.code == sf::Mouse::Right) {
	//					for (int i = 0; i < unitList.size(); i++) {
	//						if (unitList[i].isSelected) {
	//							Command moveCommand(CommandType::Move, mousePosPoint);
	//							unitList[i].commandQueue.push_back(moveCommand);
	//						}
	//					}
	//				}
	//			}
	//			//////////////////////////////////////////
	//			if (event.type == sf::Event::Closed) {
	//				window.close();
	//			}
	//		}

	//		//execute commands
	//			for (int i = 0; i < unitList.size(); i++) {
	//				//if there is a command in the queue
	//				if (!(unitList[i].commandQueue.empty())) {
	//					//if that command is a Move command
	//					if (unitList[i].commandQueue[0].type == CommandType::Move) {
	//						unitList[i].move(unitList[i].commandQueue[0]);
	//					}
	//				}
	//			}

	//		window.clear();
	//		for (int i = 0; i < unitList.size(); i++) {
	//			window.draw(unitList[i].shape);
	//		}
	//		window.display();
	//	}
	//}
	////End test block

	//Select multiple units with mouse click and shift
	{
		bool isShift = false;

		sf::RenderWindow window(sf::VideoMode(768, 640), "Window");
		window.setFramerateLimit(60);

		std::vector<Unit> unitList;
		Unit unitOne("Worker Unit", unitList.size(), UnitType::Worker, 50, 1, 32);
		unitList.push_back(unitOne);
		Unit unitTwo("Worker Unit", unitList.size(), UnitType::Worker, 50, 1, 32);
		unitList.push_back(unitTwo);
		unitList[1].setPosition(100, 100);
		Unit unitThree("Army Unit", unitList.size(), UnitType::Army, 50, 1, 48);
		unitList.push_back(unitThree);
		unitList[2].setPosition(300, 100);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				//////////////////////////////////////////
				if (event.type == sf::Event::MouseButtonReleased) {
					sf::Vector2f mousePosVector = sf::Vector2f(sf::Mouse::getPosition(window));
					Point mousePosPoint(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					if (event.key.code == sf::Mouse::Left) {
						for (int i = 0; i < unitList.size(); i++) {
							if (unitList[i].shape.getGlobalBounds().contains(mousePosVector)) {
								if (isShift && unitList[i].isSelected) {
									unitList[i].deselect();
								}
								else {
									unitList[i].select();
								}
							}
							else {
								if (!isShift) {
									unitList[i].deselect();
								}
							}
						}
					}
					else if (event.key.code == sf::Mouse::Right) {
						for (int i = 0; i < unitList.size(); i++) {
							if (unitList[i].isSelected) {
								Command moveCommand(CommandType::Move, mousePosPoint);
								unitList[i].commandQueue.push_back(moveCommand);
							}
						}
					}
				}
				else if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift) {
						isShift = true;
					}
				}
				else if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift) {
						isShift = false;
					}
				}
				//////////////////////////////////////////
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
						unitList[i].move(unitList[i].commandQueue[0]);
					}
				}
			}

			window.clear();
			for (int i = 0; i < unitList.size(); i++) {
				window.draw(unitList[i].shape);
			}
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