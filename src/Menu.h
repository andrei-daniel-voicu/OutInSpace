#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Globals.h"

class Menu
{
public:
	Menu (sf::RenderWindow&);
	bool gameQuit = false;
	bool gameStarted = false;
	void Run ();

private:
	Button start;
	Button quit;
	sf::RenderWindow& window;
	sf::Sprite background;
	void Render ();
	void ProcessEvents ();
	void Update ();

};

