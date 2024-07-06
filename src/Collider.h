#include <SFML/Graphics.hpp>
#pragma once
class Collider
{
public:
	Collider ();
	void Update (float, float);
	sf::FloatRect rect;
};

