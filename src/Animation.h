#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation ();
	void Play (sf::Sprite&, sf::Time deltaTime, int);
	sf::Texture texture;
	sf::IntRect rect;
	int lastFrame;
	float time;
	int x;
	int y;
};

