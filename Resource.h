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

	Resource()
		: maxAmount(5000), currentAmount(5000), type(ResourceType::Blue) {}
	Resource(int maxAmount, int currentAmount)
		: maxAmount(maxAmount), currentAmount(currentAmount), type(ResourceType::Blue) {}
};
