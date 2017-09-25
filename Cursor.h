#pragma once

enum CursorState {
	A, //Attack
	N, //Normal
	P, //Patrol
};

class Cursor {
private:
	CursorState state;
public:
	//Constructor
	Cursor() : state(CursorState::N) {}
	//Accessors
	CursorState getState() { return state; }
	//Mutators
	void setState(CursorState s) { state = s; }
};