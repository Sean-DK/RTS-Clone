#pragma once

#include "stdafx.h"
#include "Resource.h"

//Resource Constructor
Resource::Resource(int maxAmount)
	: maxAmount(maxAmount), currentAmount(maxAmount), type(ResourceType::Blue) {
	shape.setRadius(24);
	shape.setFillColor(sf::Color::Blue);
}