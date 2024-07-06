#include "DistanceCounter.h"
#include <iostream>


DistanceCounter::DistanceCounter ()
{
	font.loadFromFile ("Fonts\\Runic_Sans_Plain.otf");
	text.setFont (font);
	text.setCharacterSize (30);
	text.setFillColor (sf::Color::White);
}
void DistanceCounter::increment (sf::Time deltaTime, float& r)
{

	time += deltaTime.asMilliseconds ();
	if (time >= rate) {
		distance++;
		std::string str = std::to_string (distance);
		text.setString (str);
		time = 0;
	}

}

