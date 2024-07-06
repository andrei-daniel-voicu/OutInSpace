#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:
	Bullet (sf::Texture&);
	void Update (sf::Time, int);
	float speed;
	sf::Sprite sprite;

};

