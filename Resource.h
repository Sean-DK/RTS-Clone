#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//ResourceType
enum ResourceType {
	Blue,
};

//Resource
class Resource {
private:
	int maxAmount;
	int currentAmount;
	ResourceType type;
	sf::CircleShape shape;

public:

	//Constructor
	Resource(int);
	
	//Accessors
	const int getMaxAmount() { return maxAmount; }
	const int getCurrentAmount() { return currentAmount; }
	const sf::CircleShape* getShape() { return &shape; }
	const ResourceType getType() { return type; }

	//Mutators
	void setPosition(int x, int y) { shape.setPosition(x, y); }
	void setAmount(int x) { currentAmount = x; }
};
