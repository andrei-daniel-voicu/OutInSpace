#pragma once
#include "Enemy.h"
class Enemy2 : public Enemy
{
public:
	Enemy2 (sf::Texture& _texture, float _x, float _y) :Enemy (_texture, _x, _y) {}

	void Update (sf::Time);

};

