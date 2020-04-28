#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"


enum Game_State { PLAYING, MAIN_MENU, EXIT };

enum Menu_state{MAIN, OPTIONS};

class Menu
{
private:
	Menu_state option;
	int selectedItem;
	sf::Font font;
	sf::Text menu[10];
	sf::Text KeysText[10];
	sf::Texture tex;
	sf::Sprite select_sprite;
public:

	Menu(float height, float width);
	void MoveUp();
	void MoveDown();
	void CheckEvents(sf::Event ev, sf::RenderWindow *& window, Game_State & state, std::map<std::string, sf::Keyboard::Key> & keys);
	void Draw(sf::RenderWindow &window, float height, float width);
	void Init();
	int set_Key(std::map<std::string, sf::Keyboard::Key> & keys, sf::RenderWindow & window, const char* name);
	std::string exchange_key_code_to_string(int KeyCode);
	void BindKeys(std::map<std::string, sf::Keyboard::Key> & keys, sf::RenderWindow & window);
};


#endif