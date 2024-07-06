#include "AmmoCounter.h"
#include <iostream>

AmmoCounter::AmmoCounter (int _ammo) :ammo (_ammo)
{
	spritesheet.loadFromFile ("Sprites/metersheet.png");

	sprite.setTexture (spritesheet);
	sprite.setTextureRect (sf::IntRect (sprite.getTextureRect ().left, sprite.getTextureRect ().top, 240, sprite.getTextureRect ().height));
	rect = sprite.getTextureRect ();
	font.loadFromFile ("Fonts\\Runic_Sans_Plain.otf");
}

void AmmoCounter::increment ()
{
	ammo++;
	
	rect.left -= 240;
	sprite.setTextureRect (rect);

}
void AmmoCounter::decrement ()
{
	ammo--;
	rect.left += 240;
	sprite.setTextureRect (rect);

}

