#pragma once
#include <SFML/Graphics.hpp>

class HealthCounter
{
public:
	HealthCounter (sf::Texture);
	void Increment ();
	void Decrement ();
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect rect;
};

