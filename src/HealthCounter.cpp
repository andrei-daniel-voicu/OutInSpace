#include "HealthCounter.h"



HealthCounter::HealthCounter (sf::Texture _texture) :texture (_texture)
{
	sprite.setTexture (texture);
	rect = sprite.getTextureRect ();
	rect.width = 240;
	sprite.setTextureRect (rect);
}
void HealthCounter::Increment ()
{
	rect.left -= 240;
	sprite.setTextureRect (rect);

}
void HealthCounter::Decrement ()
{
	rect.left += 240;
	sprite.setTextureRect (rect);

}

