#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Stats.h"
#include "Player.h"
#include <vector>
#include <Thor/Math/Random.hpp>
#include "Enemy.h"
#include "MovingBackground.h"
#include "Pickup.h"
#include "HealthCounter.h"
#include "AmmoCounter.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "ScoreCounter.h"
#include "Particle.h"
#include "Panel.h"

class Game
{
public:
	Game (sf::RenderWindow&);
	void run ();
	std::vector<Enemy*> enemies;
	std::vector<Pickup*> pickups;
	std::vector<Particle*> particles;
	MovingBackground background;
	Player player;
	void ProcessEvents ();
	void SoundManager ();
	void Update (sf::Time);
	void Render ();
	void HandleInput (sf::Keyboard::Key, bool);
	void InputDispatcher ();
	void UpdateComponents (sf::Time);
	void CollisionCheck ();
	void ClearOffScreen ();
	void SpawnEntities (sf::Time);

	float toSpawn;
	float lastSpawn;
	float rate;
	float nrEnemies;



	struct Input
	{
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		bool shoot = false;
	}input;
	AmmoCounter ammoHUD;
	sf::Texture _ammo;

	bool gameQuit = false;

	sf::RenderWindow& window;
	HealthCounter healthHUD;
	ScoreCounter scoreHUD;
	Panel panelHUD;

	sf::SoundBuffer heartbeatBuffer;
	sf::Sound heartbeatSound;
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
	sf::Music music;


};

