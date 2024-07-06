#pragma once
#include "SFML/Graphics.hpp"

class ScoreCounter
{
public:
	ScoreCounter ();
	void Increment (int);
	int score;
	int maxNumerals;
	int currentNumerals;
	sf::Text text;
	sf::Font font;
};

