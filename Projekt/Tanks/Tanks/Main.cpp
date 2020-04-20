#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "Game");
	Menu menu(window.getSize().x, window.getSize().y);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			menu.CheckEvents(event, window);
		}

		window.clear(sf::Color::Black);
		
		menu.Draw(window, window.getSize().x, window.getSize().y);
		window.display();
	}

	return 0;
}