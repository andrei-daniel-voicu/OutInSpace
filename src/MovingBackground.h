#pragma once
#include <SFML/Graphics.hpp>
#include <Thor/Math/Random.hpp>
#include <vector>

class MovingBackground
{
public:
	MovingBackground ();
	void update (sf::Time);
	sf::Sprite background_1;
	sf::Sprite background_2;
	sf::Sprite sprites[70];
	sf::Texture textures[4];
	sf::Texture texture;

	float speed;

};

