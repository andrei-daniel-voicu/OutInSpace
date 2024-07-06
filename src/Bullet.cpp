#include "Bullet.h"



Bullet::Bullet (sf::Texture& texture)
{
	sprite.setTexture (texture);
	sprite.setScale (0.5f, 0.5f);
	speed = 1000;
}
void Bullet::Update (sf::Time deltaTime, int direction)
{
	sf::Vector2f movement;
	movement.y = -speed * direction;
	sprite.move (movement*deltaTime.asSeconds ());
}

