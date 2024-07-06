#include <iostream>
#include "Game.h"
#include "Menu.h"
#include <fstream>
#include <string>
#include <vector>
#include "Globals.h"

std::ifstream statsIn ("Stats.txt");
std::ifstream assetIN ("Textures.txt");


void setStats (Player &player)
{
	std::string str;
	getline (statsIn, str, ':');
	statsIn >> player.speed;
	getline (statsIn, str, ':');
	statsIn >> player.health;
}
void AssetLoading ()
{
	_bulletTexture.loadFromFile ("Sprites/bullet.png");
	_enemyBulletTexture.loadFromFile ("Sprites/enemy_bullet.png");
	_backgroundTexture.loadFromFile ("Textures/menu_background.png");
	_buttonTexture.loadFromFile ("Textures/button.png");
	_enemyTexture.loadFromFile ("Sprites/enemy1.png");
	_counterTexture.loadFromFile ("Sprites/meter1.png");
	_healthPickupTexture.loadFromFile("Sprites/medkit2.png");
	_explosionTexture.loadFromFile ("Sprites/explosion.png");
	_panelTexture.loadFromFile ("Sprites/panel.png");
	_healthTexture.loadFromFile ("Sprites/lifecore.png");
	_ammoPickupTexture.loadFromFile ("Sprites/ammo.png");



}

int main ()
{

	AssetLoading ();
	sf::RenderWindow window (sf::VideoMode::getDesktopMode (), "OutInSpace", sf::Style::Fullscreen);
	windowSizeX = window.getSize ().x;
	windowSizeY = window.getSize ().y;
	Menu *menu = new Menu (window);
	menu->Run ();
	while (menu->gameQuit == false)
	{
		delete menu;
		Game *game = new Game (window);
		statsIn.clear ();
		statsIn.seekg (0, std::ios::beg);
		setStats (game->player);
		game->run ();
		delete game;
		menu = new Menu (window);
		menu->Run ();
	}
	return 0;
}
