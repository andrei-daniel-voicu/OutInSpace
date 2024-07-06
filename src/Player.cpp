#include "Player.h"

Player::Player ()
{
	texture.loadFromFile ("Sprites/player.png");
	sprite.setTexture (texture);
	anim.texture.loadFromFile ("Sprites/player_anim.png");
	anim.rect = sprite.getTextureRect ();
	anim.x = anim.texture.getSize ().x;
	anim.y = anim.texture.getSize ().y;
	setOriginCenter ();
	sprite.setScale (0.5f, 0.5f);
	collider.rect = sf::FloatRect (sprite.getGlobalBounds ().left + 75, sprite.getGlobalBounds ().top,
		sprite.getGlobalBounds ().width - 150, sprite.getGlobalBounds ().height - 50);
	leftMargin = sprite.getGlobalBounds ().width *0.5f ;
	rightMargin = sprite.getGlobalBounds ().width;
	topMargin = sprite.getGlobalBounds ().height *0.5f;
	bottomMargin = sprite.getGlobalBounds ().height -80;
	sprite.setPosition (windowSizeX / 2, windowSizeY / 2);

}

void Player::Update (sf::Time deltaTime)
{
	collider.Update (sprite.getGlobalBounds ().top, sprite.getGlobalBounds ().left + 75);
	if ((sprite.getPosition ().x - leftMargin <= 0) && movement.x < 0) movement.x = 0;
	else if ((sprite.getPosition ().x + rightMargin >= windowSizeX-240) && movement.x > 0) movement.x = 0;
	if ((sprite.getPosition ().y - topMargin <= 0) && movement.y < 0) movement.y = 0;
	else if ((sprite.getPosition ().y + bottomMargin >= windowSizeY) && movement.y > 0) movement.y = 0;
	if (movement.x&&movement.y)
		movement /= 1.4f;
	sprite.move (movement.x*deltaTime.asSeconds (), movement.y*deltaTime.asSeconds ());
	if (movement == sf::Vector2f (0, 0))
	{
		state = idle;
	}
	else
	{
		if (movement.x && !movement.y)
			state = moving;
		else if (movement.y < 0)
			state = boost;

	}
	switch (state)
	{
	case 0:	anim.Play (sprite, deltaTime, 2);
		break;
	case 1:	anim.Play (sprite, deltaTime, 2);
		break;
	case 2:	anim.Play (sprite, deltaTime, 1);
		break;
	}
	
	lastFire += deltaTime.asSeconds ();
}
void Player::setOriginCenter ()
{
	sprite.setOrigin (sprite.getLocalBounds ().width / 2, sprite.getLocalBounds ().height / 2);
}
void Player::Shoot ()
{
	
	bullets.push_back (new Bullet (_bulletTexture));
	bullets.back ()->sprite.setPosition (sprite.getPosition ().x - sprite.getGlobalBounds ().width / 2 + 23, sprite.getPosition ().y - 100);
	bullets.back ()->speed += this->speed;
	bullets.push_back (new Bullet (_bulletTexture));
	bullets.back ()->sprite.setPosition (sprite.getPosition ().x + sprite.getGlobalBounds ().width / 2 - 139, sprite.getPosition ().y - 100);
	bullets.back ()->speed += this->speed;
	lastFire = 0;

}
