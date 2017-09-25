#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Point
class Point {
public:
	float x;
	float y;

	Point() {}
	Point(float, float);
	Point(sf::Vector2f);

	Point* operator=(Point);
};