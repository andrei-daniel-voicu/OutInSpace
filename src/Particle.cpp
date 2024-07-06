#include "Particle.h"
#include <iostream>
Particle::Particle (sf::Texture _texture) : texture (_texture)
{
	frameDuration = 0.15f;
	currentFrame = 1;
	nrFrames = 3;
	toDestroy = false;
	sprite.setTexture (texture);
	rect = sprite.getTextureRect ();
	rect.width = 240;
	sprite.setTextureRect (rect);
}

void Particle::Update (sf::Time deltaTime)
{
	time += deltaTime.asSeconds ();
	if (time >= frameDuration && currentFrame < nrFrames)
	{

		rect.left += 240;
		time = 0;
		currentFrame++;
		sprite.setTextureRect (rect);
		float randomScale = thor::random (0.5f, 1.6f);
		sprite.setScale (randomScale, randomScale);
		sprite.setPosition (sprite.getPosition ().x + thor::random (0.5f, 1.6f), sprite.getPosition ().y + thor::random (0.5f, 1.6f));
	}

}