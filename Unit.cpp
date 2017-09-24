#pragma once

#include "stdafx.h"
#include "Unit.h"

//Unit Constructor
Unit::Unit(UnitName n, int id, Controller* c)
	: name(n), unitID(id), controller(c) {
	switch (this->name) {
	case UnitName::Marine:
		type = UnitType::Army;
		maxHealth = 50;
		currentHealth = 50;
		speed = 1;
		break;
	case UnitName::Medic:
		type = UnitType::Army;
		maxHealth = 50;
		currentHealth = 50;
		speed = 1;
		break;
	case UnitName::Tank:
		type = UnitType::Army;
		maxHealth = 75;
		currentHealth = 75;
		speed = 0.5;
		break;
	case UnitName::SCV:
		type = UnitType::Worker;
		maxHealth = 25;
		currentHealth = 25;
		speed = 1;
		shape.setSize(sf::Vector2f(32, 32));
		break;
	}
}

//Overloads
bool Unit::operator==(Unit* u) {
	if (this->unitID == u->unitID) return true;
	else return false;
}

//Select
void Unit::select() {
	if (!selected) {
		selected = true;
		shape.setFillColor(sf::Color::Red);
	}
}

//Deselect
void Unit::deselect() {
	if (selected) {
		selected = false;
		shape.setFillColor(sf::Color::White);
	}
}

//Set command, overwrites any old commands
void Unit::setCommand(Command* c) {
	if (commandQueue.empty()) { commandQueue.push_back(c); }
	else {
		commandQueue.clear();
		commandQueue.push_back(c);
	}
}

//Command engine
void Unit::executeCommand() {
	if (!commandQueue.empty()) {
		switch (commandQueue.front()->type) {
		case CommandType::Attack:
			attack(static_cast<AttackCommand*>(commandQueue.front()));
			break;
		case CommandType::Gather:
			gather(static_cast<GatherCommand*>(commandQueue.front()));
			break;
		case CommandType::Move:
			move(static_cast<MoveCommand*>(commandQueue.front()));
			break;
		}
	}
}

//Attack, executes an attack command
void Unit::attack(AttackCommand* command) {}

//Gather, executes a gather command
//TODO: fix pathing and timing
//TODO: when giving "Gather" command and holding shift the unit walks offscreen and is lost
void Unit::gather(GatherCommand* command) {
	//Check for completion
	if (commandQueue.front()->completed) {
		//If there is a command waiting, stop gathering
		if (commandQueue.size() > 1) {
			commandQueue.erase(commandQueue.begin());
		}
		//Otherwise continue gathering
		else {
			commandQueue.front()->completed = false;
		}
	}
	else {
		//If the unit is NOT currently holding a resource (AKA gathering), move towards resource
		//TODO: change variable name of "gathering"
		if (!gathering) {
			command->endPoint->x = command->target->getShape()->getPosition().x;
			command->endPoint->y = command->target->getShape()->getPosition().y;
		}
		else {
			command->endPoint->x = 0;
			command->endPoint->y = 0;
		}
		//Move x
		if (shape.getPosition().x > command->endPoint->x) {
			setPosition(shape.getPosition().x - speed, shape.getPosition().y);
		}
		else if (shape.getPosition().x < command->endPoint->x) {
			setPosition(shape.getPosition().x + speed, shape.getPosition().y);
		}
		//Move y
		if (shape.getPosition().y > command->endPoint->y) {
			setPosition(shape.getPosition().x, shape.getPosition().y - speed);
		}
		else if (shape.getPosition().y < command->endPoint->y) {
			setPosition(shape.getPosition().x, shape.getPosition().y + speed);
		}
		if (shape.getPosition().x == command->endPoint->x
			&& shape.getPosition().y == command->endPoint->y) {
			if (!gathering) {
				gathering = true;
				commandQueue.front()->completed = true;
			}
			else {
				gathering = false;
				commandQueue.front()->completed = true;
			}
		}
	}
}

//Move, executes a move command
//TODO: fix pathing
void Unit::move(MoveCommand* command) {
	//check for completed command
	if (commandQueue.front()->completed) {
		commandQueue.erase(commandQueue.begin());
	}
	else {
		//move x
		if (shape.getPosition().x > command->endPoint.x) {
			setPosition(shape.getPosition().x - speed, shape.getPosition().y);
		}
		else if (shape.getPosition().x < command->endPoint.x) {
			setPosition(shape.getPosition().x + speed, shape.getPosition().y);
		}
		//move y
		if (shape.getPosition().y > command->endPoint.y) {
			setPosition(shape.getPosition().x, shape.getPosition().y - speed);
		}
		else if (shape.getPosition().y < command->endPoint.y) {
			setPosition(shape.getPosition().x, shape.getPosition().y + speed);
		}
		//complete
		if (shape.getPosition().x == command->endPoint.x
			&& shape.getPosition().y == command->endPoint.y) {
			commandQueue.front()->completed = true;
		}
		else {
			//check for collisions with other units
			//TODO: change path rather than terminate command
			for (int i = 0; i < controller->getUnitSize(); i++) {
				if (this != controller->getUnits()[i]) {
					if (shape.getGlobalBounds().intersects(controller->getUnits()[i]->getShape()->getGlobalBounds())) {
						commandQueue.front()->completed = true;
					}
				}
			}
		}
	}
}