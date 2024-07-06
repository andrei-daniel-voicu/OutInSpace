#include "Enemy2.h"



void Enemy2::Update (sf::Time deltaTime)
{
	sf::Vector2f movement;
	movement.y = speed;
	move (movement*deltaTime.asSeconds ());
	int dice = thor::random (1, chance);
	if (lastFire >= toFire)
	{
		if (dice == chance)
		{
			Shoot ();
			lastFire = 0;
		}

	}
	for (int i = 0; i < bullets.size (); i++)
	{
		bullets[i]->Update (deltaTime, -1);
	}
	lastFire += deltaTime.asSeconds ();
}