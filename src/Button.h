#pragma once
#include <SFML/Graphics.hpp>
class Button
{
public:
	Button ();
	bool hovered ();
	bool pressed (sf::Event event);
	void setOriginCenter ();
	sf::Sprite sprite;	
	sf::Text text;
};

