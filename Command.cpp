#pragma once

#include "stdafx.h"
#include "Command.h"

//Command Constructor
Command::Command(CommandType type)
	: type(type), completed(false) {}

//AttackCommand Constructor
AttackCommand::AttackCommand(Unit* u)
	: Command(CommandType::Attack), target(u) {}

//GatherCommand Constructor
GatherCommand::GatherCommand(Resource* r)
	: Command(CommandType::Gather), target(r) {
	endPoint = new Point(0, 0);
}

//MoveComand Constructor
MoveCommand::MoveCommand(Point p)
	: Command(CommandType::Move), endPoint(p) {}