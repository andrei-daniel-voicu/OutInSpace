#pragma once
#include <SFML/Graphics.hpp>
#include <Thor/Math/Random.hpp>

class Pickup
{
public:
	Pickup (sf::Texture&, std::string, float, float);
	void Update (sf::Time);
	sf::Sprite sprite;
	float speed;
	float time;
	std::string type;
};

