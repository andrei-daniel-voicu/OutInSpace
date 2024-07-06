#pragma once
#include "SFML/Graphics.hpp"
class Panel
{
public:
	Panel (sf::Texture);
	void Update (sf::Time deltaTime);
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect rect;

	float time;
	float frameDuration;
	int lastFrame;
};

