#include "Animation.h"
#include <iostream>


Animation::Animation ()
{
	
	lastFrame = 0;
}

void Animation::Play (sf::Sprite& _sprite, sf::Time _deltaTime, int _height)
{
	time += _deltaTime.asSeconds ();
	if (((_height - 1) * 240) != rect.top)
	{
		rect.left = 0;
		lastFrame = 0;
		rect.top = (_height - 1) * 240;

	}
	_sprite.setTexture (texture);

	if (time >= 0.3f)
	{

		if (rect.left + 240 >= x) {
			rect.left = 0;
			lastFrame = 0;
		}
		else
		{
			lastFrame++;
			rect.left += 240;
		}

		time = 0;

	}
	_sprite.setTextureRect (rect);

}

