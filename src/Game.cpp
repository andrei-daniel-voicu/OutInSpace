#include "Game.h"
#include "Globals.h"
#include <iostream>
Game::Game (sf::RenderWindow& _window) :window (_window), healthHUD (_healthTexture), background (), ammoHUD (9), panelHUD (_panelTexture)
{
	window.setMouseCursorVisible (false);
}

void Game::run ()
{
	soundBuffer.loadFromFile ("Sounds/Laser1.wav");
	heartbeatBuffer.loadFromFile ("Sounds/HeartBeat.wav");
	heartbeatSound.setBuffer (heartbeatBuffer);
	heartbeatSound.setLoop (true);

	music.openFromFile ("Sounds/Music.wav");
	music.play ();
	music.setVolume (50);
	music.setLoop (true);
	scoreHUD.text.setPosition (windowSizeX - scoreHUD.text.getGlobalBounds ().width - 50, 50);
	panelHUD.sprite.setPosition (windowSizeX - panelHUD.sprite.getGlobalBounds ().width, 0);
	healthHUD.sprite.setPosition (windowSizeX - panelHUD.sprite.getGlobalBounds ().width, 0 + panelHUD.sprite.getGlobalBounds ().height / 3 - 100);
	ammoHUD.sprite.setPosition (windowSizeX - ammoHUD.sprite.getGlobalBounds ().width - 20, windowSizeY - ammoHUD.sprite.getGlobalBounds ().height - 175);

	sf::Clock clock;
	toSpawn = 2.f;
	rate = 1.2f;
	nrEnemies = 4;
	spawnAreaX = windowSizeX - panelHUD.rect.width;
	spawnAreaY = windowSizeY;

	for (int i = 0; i < 70; i++)
	{
		background.sprites[i].setPosition (thor::random (0, spawnAreaX), thor::random (-spawnAreaY, -10));

	}
	while (window.isOpen () && gameQuit == false)
	{
		sf::Time deltaTime = clock.restart ();
		if (player.health <= 0) gameQuit = true;
		ProcessEvents ();
		Update (deltaTime);
		Render ();
	}
}
void Game::ProcessEvents ()
{
	sf::Event event;
	while (window.pollEvent (event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: window.close ();
			break;
		case sf::Event::KeyPressed:  HandleInput (event.key.code, true);
			break;
		case sf::Event::KeyReleased:  HandleInput (event.key.code, false);
			break;
		}

	}
}
void Game::Update (sf::Time deltaTime)
{
	if (player.health <= 0)
		return;
	InputDispatcher ();
	SoundManager ();
	UpdateComponents (deltaTime);
	background.update (deltaTime);
	ClearOffScreen ();
	CollisionCheck ();
	SpawnEntities (deltaTime);



}

void Game::Render ()
{
	window.clear ();
	window.draw (background.background_1);
	window.draw (background.background_2);
	for (int i = 0; i < 70; i++)
	{
		window.draw (background.sprites[i]);

	}
	window.draw (player.sprite);
	for (int i = 0; i < enemies.size (); i++)
	{
		window.draw (enemies[i]->sprite);
		for (int j = 0; j < enemies[i]->bullets.size (); j++)
		{
			window.draw (enemies[i]->bullets[j]->sprite);
		}
	}
	for (int i = 0; i < particles.size (); i++)
	{
		window.draw (particles[i]->sprite);
	}
	for (int i = 0; i < pickups.size (); i++)
		window.draw (pickups[i]->sprite);
	for (int i = 0; i < player.bullets.size (); i++)
		window.draw (player.bullets[i]->sprite);
	window.draw (panelHUD.sprite);
	window.draw (healthHUD.sprite);
	window.draw (ammoHUD.sprite);
	window.draw (scoreHUD.text);
	window.display ();
}
void Game::HandleInput (sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::Key::W: input.up = isPressed;
		break;
	case sf::Keyboard::Key::S: input.down = isPressed;
		break;
	case sf::Keyboard::Key::A: input.left = isPressed;
		break;
	case sf::Keyboard::Key::D: input.right = isPressed;
		break;
	case sf::Keyboard::Key::Space: input.shoot = isPressed;
		break;
	default:
		break;
	}


}

void Game::CollisionCheck ()
{
	for (int i = 0; i < enemies.size (); i++)
		if (player.collider.rect.intersects ((enemies[i]->sprite.getGlobalBounds ())))
		{
			delete enemies[i];
			enemies.erase (enemies.begin () + i);
			player.health--;
			music.setPitch (music.getPitch () + 0.05f);
			healthHUD.Decrement ();
		}
	for (int i = 0; i < pickups.size (); i++)
		if (player.collider.rect.intersects ((pickups[i]->sprite.getGlobalBounds ())))
		{

			if (pickups[i]->type == "Health")
			{
				std::cout << " DA" << std::endl;

				if (player.health < 5)
				{
					music.setPitch (music.getPitch () - 0.05f);
					player.health++;
					healthHUD.Increment ();
				}
			}
			else
			{
				if (ammoHUD.ammo <= player.ammo)
					ammoHUD.increment ();
			}
			delete pickups[i];
			pickups.erase (pickups.begin () + i);
		}
	for (int j = 0; j < player.bullets.size (); j++)
		for (int i = 0; i < enemies.size (); i++)
			if (player.bullets[j]->sprite.getGlobalBounds ().intersects (enemies[i]->sprite.getGlobalBounds ()))
			{
				scoreHUD.Increment (enemies[i]->score);
				particles.push_back (new Particle (_explosionTexture));
				particles.back ()->sprite.setPosition (enemies[i]->sprite.getPosition ());

				pickups.push_back (new Pickup (_healthPickupTexture, "Health", 0, spawnAreaX));
				pickups.back ()->sprite.setPosition (enemies[i]->sprite.getPosition ());

				delete enemies[i];
				enemies.erase (enemies.begin () + i);

				delete player.bullets[j];
				player.bullets.erase (player.bullets.begin () + j);
				break;


			}

	for (int i = 0; i < enemies.size (); i++)
	{
		for (int j = 0; j < enemies[i]->bullets.size (); j++)
		{

			if (enemies[i]->bullets[j]->sprite.getGlobalBounds ().intersects (player.collider.rect))
			{
				player.health--;
				music.setPitch (music.getPitch () + 0.05f);
				healthHUD.Decrement ();
				delete enemies[i]->bullets[j];
				enemies[i]->bullets.erase (enemies[i]->bullets.begin () + j);
			}
		}
	}

}
void Game::ClearOffScreen ()
{
	for (int i = 0; i < enemies.size (); i++)
		if (enemies[i]->sprite.getPosition ().y > windowSizeX + 100)
		{
			delete enemies[i];
			enemies.erase (enemies.begin () + i);
		}
	for (int i = 0; i < pickups.size (); i++)
		if (pickups[i]->sprite.getPosition ().y > windowSizeY + 100)
		{
			delete pickups[i];
			pickups.erase (pickups.begin () + i);
		}
	for (int i = 0; i < player.bullets.size (); i++)
		if (player.bullets[i]->sprite.getPosition ().y < -100)
		{
			delete player.bullets[i];
			player.bullets.erase (player.bullets.begin () + i);
		}
	for (int i = 0; i < enemies.size (); i++)
		for (int j = 0; j < enemies[i]->bullets.size (); j++)
		{
			if (enemies[i]->bullets[j]->sprite.getPosition ().y < -100)
			{
				delete enemies[i]->bullets[j];
				enemies[i]->bullets.erase (enemies[i]->bullets.begin () + j);

			}
		}
	for (int i = 0; i < particles.size (); i++)
	{
		if (particles[i]->currentFrame >= particles[i]->nrFrames)
		{

			delete particles[i];
			particles.erase (particles.begin () + i);
		}

	}
	for (int i = 0; i < 70; i++)
	{
		if (background.sprites[i].getPosition ().y > windowSizeY + 20)
		{
			float scale = thor::random (0.5f, 3.f);
			background.sprites[i].setPosition (thor::random (0, spawnAreaX), thor::random (-spawnAreaY, -10));
			int dice = thor::random (0, 3);
			background.sprites[i].setTexture (background.textures[dice]);
			background.sprites[i].setScale (scale, scale);


		}
	}
}
void Game::InputDispatcher ()
{
	player.movement = sf::Vector2f (0, 0);
	if (input.left) player.movement.x -= player.speed;
	if (input.right) player.movement.x += player.speed;
	if (input.down) player.movement.y += player.speed;
	if (input.up) player.movement.y -= player.speed;
	if (input.shoot&&player.lastFire >= player.fireRate && ammoHUD.ammo > 0)
	{
		sound.setBuffer (soundBuffer);
		sound.play ();
		player.Shoot ();
		ammoHUD.decrement ();

	}

}
void Game::UpdateComponents (sf::Time deltaTime)
{
	player.Update (deltaTime);
	panelHUD.Update (deltaTime);
	for (int i = 0; i < pickups.size (); i++)
	{

		pickups[i]->Update (deltaTime);
	}

	for (int i = 0; i < enemies.size (); i++)
	{
		enemies[i]->Update (deltaTime);

	}
	for (int i = 0; i < player.bullets.size (); i++)
	{
		player.bullets[i]->Update (deltaTime, 1);

	}
	for (int i = 0; i < particles.size (); i++) {
		particles[i]->Update (deltaTime);
	}

}
void Game::SpawnEntities (sf::Time deltaTime)
{
	lastSpawn += deltaTime.asSeconds ();
	if (lastSpawn >= toSpawn / rate)
	{

		pickups.push_back (new Pickup (_ammoPickupTexture, "Ammo", 0, spawnAreaX));
		lastSpawn = 0.f;
		toSpawn = thor::random (2.f, 3.f);
		for (int i = 0; i < nrEnemies; i++)
		{
			enemies.push_back (new Enemy2 (_enemyTexture, 0, spawnAreaX));
		}


	}
}
void Game::SoundManager ()
{
	if (player.health == 1 && heartbeatSound.getStatus () != heartbeatSound.Playing)
	{
		heartbeatSound.play ();
	}
	else if (player.health != 1 && heartbeatSound.getStatus () == heartbeatSound.Playing)
	{
		heartbeatSound.stop ();
	}
}
