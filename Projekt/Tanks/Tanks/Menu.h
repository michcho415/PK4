#ifndef MENU_H
#define MENU_H

#include "OriginandPositionTemplate.h"
#include "SFML/Graphics.hpp"
enum Difficulty { EASY, MEDIUM, HARD };

enum Keys { UP, DOWN, LEFT, RIGHT, SHOOT, ENTER, ESCAPE };

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
	sf::Text press_key;
	sf::Texture tex;
	sf::Texture title;
	sf::Sprite select_sprite;
	sf::Sprite Title;
public:

	Menu(sf::RenderWindow *& window);
	void MoveUp();
	void MoveDown();
	void CheckEvents(sf::Event ev, sf::RenderWindow *& window, std::map<Keys, sf::Keyboard::Key> & keys);
	void Draw(sf::RenderWindow *&window);
	void Init();
	int set_Key(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window, enum Keys id);
	std::string exchange_key_code_to_string(int KeyCode);
	void BindKeysandChangeDifficulty(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window);
	std::string Difficulty_to_string(Difficulty diff);
};


#endif