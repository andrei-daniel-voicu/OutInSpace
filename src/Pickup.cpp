#include "Pickup.h"



Pickup::Pickup (sf::Texture& texture, std::string _type, float _min, float _max)
{
	sprite.setTexture (texture);
	sprite.setScale (0.8f, 0.8f);
	if (_type == "Ammo") {
		sprite.setPosition (thor::random (_min, _max), 0);
		sprite.setScale (0.5f, 0.5f);
		speed = 400.f;

	}
	if (_type == "Health") {
		speed = 300.f;

	}
	type = _type;
}


void Pickup::Update (sf::Time deltaTime)
{
	sf::Vector2f movement;
	movement.y = speed;
	sprite.move (movement*deltaTime.asSeconds ());
}

