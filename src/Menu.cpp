#include "Menu.h"

Menu::Menu (sf::RenderWindow& _window) :window (_window), gameQuit (false)
{
	window.setMouseCursorVisible (true);
	background.setTexture (_backgroundTexture);
	start.sprite.setTexture (_buttonTexture);
	quit.sprite.setTexture (_buttonTexture);
}

void Menu::Run ()
{
	start.setOriginCenter ();
	quit.setOriginCenter ();

	start.sprite.setPosition (window.getSize ().x *0.5f, window.getSize ().y *0.2f);
	quit.sprite.setPosition (window.getSize ().x *0.5f, window.getSize ().y *0.8f);

	sf::Font _font;
	_font.loadFromFile ("Fonts\\Runic_Sans_Plain.otf");

	start.text.setFont (_font);
	start.text.setString ("Start");
	start.text.setCharacterSize (60);
	start.text.setFillColor (sf::Color::Black);
	start.text.setPosition (start.sprite.getPosition ().x - 110, start.sprite.getPosition ().y - 40);

	quit.text.setFont (_font);
	quit.text.setString ("Quit");
	quit.text.setCharacterSize (60);
	quit.text.setFillColor (sf::Color::Black);
	quit.text.setPosition (quit.sprite.getPosition ().x - 80, quit.sprite.getPosition ().y - 30);


	while (window.isOpen () && gameQuit == false && gameStarted == false)
	{
		ProcessEvents ();
		Render ();
		Update ();
	}
}

void Menu::ProcessEvents ()
{
	sf::Event event;
	while (window.pollEvent (event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: {
			gameQuit = true;
			window.close ();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (quit.pressed (event))
			{
				gameQuit = true;
				window.close ();

			}
			else if (start.pressed (event))
			{
				gameStarted = true;
			}
			break;

		}
		}
	}
}
void Menu::Update ()
{

}
void Menu::Render ()
{
	window.draw (background);
	window.draw (start.sprite);
	window.draw (start.text);
	window.draw (quit.sprite);
	window.draw (quit.text);
	window.display ();
}

