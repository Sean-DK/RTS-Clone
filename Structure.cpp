#include "stdafx.h"
#include "Structure.h"

Structure::Structure(StructureType s, int id, Controller* c) 
	: type(s), structureID(id), controller(c) {
	//TODO: add health and armor and stuff based on structure type
}
