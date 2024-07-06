#pragma once
#include <SFML/Graphics.hpp>
#include <Thor/Math/Random.hpp>
#include <iostream>
#include "Bullet.h"
#include "Globals.h"

class Enemy
{
public:
	Enemy (sf::Texture&, float, float);
	virtual void Update (sf::Time);
	void Shoot ();
	void updatePosition (float, float);
	void updateSpeed ();
	void move (sf::Vector2f);

	sf::Sprite sprite;
	std::vector<Bullet*> bullets;


	float speed;
	float toFire;
	float lastFire;

	int score;
	int health;
	int chance;

};

