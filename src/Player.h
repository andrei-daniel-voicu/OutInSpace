#pragma once
#include "Collider.h"
#include "Bullet.h"
#include "Animation.h"
#include "Globals.h"

class Player
{
public:
	Player ();
	void Update (sf::Time deltaTime);
	void setOriginCenter ();
	void Shoot ();
	sf::Sprite sprite;
	sf::Texture texture;
	Collider collider;
	enum AnimState
	{
		idle,
		moving,
		boost,
	};
	AnimState state;
	Animation anim;
	std::vector<Bullet*> bullets;
	sf::Vector2f movement;
	
	float speed;
	int health;
	float fireRate = 0.7f;
	float lastFire;
	int ammo = 8;
	float leftMargin;
	float rightMargin;
	float topMargin;
	float bottomMargin;
};

