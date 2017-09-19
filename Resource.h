#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum ResourceType {
	Blue,
};

class Resource {
public:
	int maxAmount;
	int currentAmount;
	ResourceType type;
	sf::CircleShape shape;

	Resource() 
		: maxAmount(500), currentAmount(500), type(ResourceType::Blue) {
		shape.setRadius(24);
		shape.setFillColor(sf::Color::Blue);
	}

	Resource(int maxAmount)
		: maxAmount(maxAmount), currentAmount(maxAmount), type(ResourceType::Blue) {
		shape.setRadius(24);
		shape.setFillColor(sf::Color::Blue);
	}
};
