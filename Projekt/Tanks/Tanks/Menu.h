#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"


enum State { PLAYING, MAIN_MENU, OPTIONS, EXIT };

class Menu
{
private:
	State option;
	int selectedItem;
	sf::Font font;
	sf::Text menu[10];
	sf::Texture tex;
	sf::Sprite select_sprite;
public:

	Menu(float height, float width);
	void MoveUp();
	void MoveDown();
	void CheckEvents(sf::Event ev, sf::RenderWindow & window);
	void Draw(sf::RenderWindow &window, float height, float width);

};


#endif