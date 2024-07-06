#include "Panel.h"



Panel::Panel (sf::Texture _texture) :texture (_texture)
{
	frameDuration = 1.f;
	lastFrame = 1;
	sprite.setTexture (texture);
	rect = sprite.getTextureRect ();
	rect.width = 240;
	sprite.setTextureRect (rect);
}
void Panel::Update (sf::Time deltaTime)
{
	time += deltaTime.asSeconds ();

	if (time >= frameDuration)
	{
		if (lastFrame >= 6)
		{
			rect.left = 0;
			sprite.setTextureRect (rect);

			lastFrame = 1;
		}
		else
		{
			rect.left += 240;
			lastFrame++;
			sprite.setTextureRect (rect);
			time = 0;
		}

	}
}


