#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum ResourceType {
	Blue,
};

class Resource {
private:
	int maxAmount;
	int currentAmount;
	ResourceType type;
	sf::CircleShape shape;

public:

	//constructor
	Resource(int);
	//Getters
	const int getMaxAmount() { return maxAmount; }
	const int getCurrentAmount() { return currentAmount; }
	const sf::CircleShape* getShape() { return &shape; }
	const ResourceType getType() { return type; }

	//Setters
	void setPosition(int x, int y) { shape.setPosition(x, y); }
	void setAmount(int x) { currentAmount = x; }
};
