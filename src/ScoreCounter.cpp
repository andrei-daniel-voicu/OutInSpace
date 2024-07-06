#include "ScoreCounter.h"

ScoreCounter::ScoreCounter ()
{

	font.loadFromFile ("Fonts/DroidSerif-Regular.otf");
	text.setFont (font);
	text.setCharacterSize (50);
	text.setFillColor (sf::Color::White);

	score = 0;
	maxNumerals = 5;

	std::string dummy;
	for (int i = 0; i < maxNumerals; i++)
		dummy.push_back ('0');

	text.setString (dummy);
}
void ScoreCounter::Increment (int _value)
{
	score += _value;
	int nr = 0, score_copy = score;
	std::string dummy;
	if (score_copy < 10)
	{
		nr = 1;
	}
	else {
		while (score_copy)
		{
			nr++;
			score_copy /= 10;
		}
	}
	currentNumerals = nr;
	for (int i = 0; i < maxNumerals - currentNumerals; i++)
		dummy.push_back ('0');
	text.setString (dummy + std::to_string (score));
}

