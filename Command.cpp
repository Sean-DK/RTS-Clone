#pragma once

#include "stdafx.h"
#include "Command.h"

Command::Command(CommandType type)
	: type(type), completed(false) {}

AttackCommand::AttackCommand(Unit* u)
	: Command(CommandType::Attack), target(u) {}

GatherCommand::GatherCommand(Resource* r)
	: Command(CommandType::Gather), target(r) {
	endPoint = new Point(0, 0);
}

MoveCommand::MoveCommand(Point p)
	: Command(CommandType::Move), endPoint(p) {}