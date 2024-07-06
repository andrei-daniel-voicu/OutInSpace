#pragma once
#include <SFML/Graphics.hpp>

class AmmoCounter
{
public:
	AmmoCounter (int);
	void increment ();
	void decrement ();
	sf::Font font;
	sf::Sprite sprite;
	sf::Texture spritesheet;
	sf::IntRect rect;
	int ammo;
};

