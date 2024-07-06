#include "Enemy.h"

Enemy::Enemy (sf::Texture& _texture, float _min, float _max)
{
	score = 40;
	sprite.setTexture (_texture);
	sprite.setScale (0.5f, 0.5f);
	updateSpeed ();
	updatePosition (_min, _max);
	toFire = 1;
	lastFire = toFire;
	chance = 4;
}
void Enemy::updatePosition (float _min, float _max)
{
	sprite.setPosition (thor::random (_min, _max), -100);
}
void Enemy::move (sf::Vector2f movement)
{
	sprite.move (movement.x, movement.y);
}
void Enemy::updateSpeed ()
{
	speed = thor::random (500.f, 900.f);
}
void Enemy::Update (sf::Time deltaTime)
{
}
void Enemy::Shoot ()
{
	bullets.push_back (new Bullet (_enemyBulletTexture));
	bullets.back ()->sprite.setPosition (sprite.getPosition ().x - sprite.getGlobalBounds ().width / 2 + 85, sprite.getPosition ().y + sprite.getGlobalBounds ().height / 2 - 18);
	bullets.back ()->speed += this->speed;
	bullets.push_back (new Bullet (_enemyBulletTexture));
	bullets.back ()->sprite.setPosition (sprite.getPosition ().x + sprite.getGlobalBounds ().width / 2 - 83, sprite.getPosition ().y + sprite.getGlobalBounds ().height / 2 - 18);
	bullets.back ()->speed += this->speed;

}

