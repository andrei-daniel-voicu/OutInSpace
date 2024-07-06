#include "MovingBackground.h"



MovingBackground::MovingBackground ()
{
	textures[0].loadFromFile ("Sprites/Stars1.png");
	textures[1].loadFromFile ("Sprites/Stars2.png");
	textures[2].loadFromFile ("Sprites/Stars3.png");
	textures[3].loadFromFile ("Sprites/Stars4.png");

	for (int i = 0; i < 70; i++)
	{
		int dice = thor::random (0, 3);
		sprites[i].setTexture (textures[dice]);
		float scale = thor::random (0.5f, 3.f);
		sprites[i].setScale (scale, scale);

	}
	texture.loadFromFile ("Textures/Background.png");
	background_1.setTexture (texture);
	background_2.setTexture (texture);
	background_1.setOrigin (background_1.getTextureRect ().left + background_1.getTextureRect ().width / 2.0f,
		background_1.getTextureRect ().top + background_1.getTextureRect ().height / 2.0f);
	background_1.setPosition (sf::Vector2f (1920 / 2.0f, 1080 / 2.0f));
	background_2.setOrigin (background_2.getTextureRect ().left + background_2.getTextureRect ().width / 2.0f,
		background_2.getTextureRect ().top + background_2.getTextureRect ().height / 2.0f);
	background_2.setPosition (background_1.getPosition ().x, -background_1.getTextureRect ().height / 2);
	speed = 60;

}

void MovingBackground::update (sf::Time deltaTime)
{

	if (background_2.getPosition ().y >= 3 * 540.f - 3)
		background_2.setPosition (background_1.getPosition ().x, -background_1.getTextureRect ().height / 2);
	else if (background_1.getPosition ().y >= 3 * 540.f - 3)
		background_1.setPosition (background_2.getPosition ().x, -background_2.getTextureRect ().height / 2);
	background_1.move (0.f, speed*deltaTime.asSeconds ());
	background_2.move (0.f, speed*deltaTime.asSeconds ());
	for (int i = 0; i < 70; i++)
	{
		sprites[i].move (0.f, 200*deltaTime.asSeconds ());
	}
}


