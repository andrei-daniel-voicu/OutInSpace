#include "Button.h"



Button::Button ()
{
}

bool Button::hovered ()
{

	if (sprite.getGlobalBounds ().contains (sf::Mouse::getPosition ().x, sf::Mouse::getPosition ().y))
		return true;
	return false;

}
bool Button::pressed (sf::Event event)
{
	if (hovered () && event.mouseButton.button == sf::Mouse::Left) return true;
	return false;
}

void Button::setOriginCenter ()
{
	sprite.setOrigin (sprite.getLocalBounds ().width / 2, sprite.getLocalBounds ().height / 2);
}
