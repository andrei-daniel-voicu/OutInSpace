#pragma once
#include "Enemy.h"
class Enemy1 : public Enemy
{
public:
	Enemy1 (sf::Texture& _texture, float _x, float _y) :Enemy (_texture, _x, _y){}
	void Update (sf::Time);
	
};

