#include "Menu.h"
#include "Game.h"
#include <iostream>

void Menu::Init()
{
	if (!tex.loadFromFile("Resources/Player1.bmp", sf::IntRect(30, 30, 30, 30)))
	{
		throw "Nie uda³o siê odczytaæ pliku Player1.bmp!";
	}
	if (!font.loadFromFile("Resources/NesFont.ttf"))
	{
		throw "Nie uda³o siê odczytaæ pliku NesFont.ttf!";
	}
}



Menu::Menu(float height, float width):selectedItem(0), option(MAIN)
{
	Init();
	
	select_sprite.setTexture(tex);
	select_sprite.setOrigin(select_sprite.getLocalBounds().width/ 2.0f, select_sprite.getLocalBounds().height/2.0f);
	select_sprite.getOrigin().x;



	//MAIN MENU
	menu[0].setString("PLAY");
	menu[0].setPosition(width / 2.0f, height / 2.0f);
		
	menu[1].setString("OPTIONS");
	menu[1].setPosition(width / 2.0f, height / 2.0f + 30);

	menu[2].setString("EXIT");
	menu[2].setPosition(width / 2.0f, height / 2.0f + 60);

	//OPTIONS
	menu[3].setString("DIFFICULTY: ");
	menu[3].setPosition(width / 2.0f - 70, height / 2.0f - 120);

	menu[4].setString("MOVE UP: ");
	menu[4].setPosition(width / 2.0f - 70, height / 2.0f - 90);
	
	menu[5].setString("MOVE DOWN: ");
	menu[5].setPosition(width / 2.0f - 70, height / 2.0f - 60);

	menu[6].setString("MOVE LEFT: ");
	menu[6].setPosition(width / 2.0f - 70, height / 2.0f - 30);

	menu[7].setString("MOVE RIGHT: ");
	menu[7].setPosition(width / 2.0f - 70, height / 2.0f);

	menu[8].setString("SHOOT: ");
	menu[8].setPosition(width / 2.0f - 70, height / 2.0f + 30);

	//default Keys
	KeysText[0].setString("UP");
	KeysText[0].setPosition(width / 2.0f + 100, height / 2.0f - 90);

	KeysText[1].setString("DOWN");
	KeysText[1].setPosition(width / 2.0f + 100, height / 2.0f - 60);

	KeysText[2].setString("LEFT");
	KeysText[2].setPosition(width / 2.0f + 100, height / 2.0f - 30);

	KeysText[3].setString("RIGHT");
	KeysText[3].setPosition(width / 2.0f + 100, height / 2.0f);

	KeysText[4].setString("SPACE");
	KeysText[4].setPosition(width / 2.0f + 100, height / 2.0f + 30);

	

	for (int i = 8; i >= 0; --i)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(15);
		menu[i].setOrigin(menu[i].getLocalBounds().left / 2.0f, menu[i].getLocalBounds().height / 2.0f);
		KeysText[i].setFont(font);
		KeysText[i].setCharacterSize(15);
		KeysText[i].setOrigin(KeysText[i].getLocalBounds().left / 2.0f, KeysText[i].getLocalBounds().height / 2.0f);
	}

}

void Menu::MoveUp()
{
	--selectedItem;
	if (option == MAIN)
	{
		if (selectedItem < 0)
		{
			selectedItem = 2;
		}
	}
	else {
		if (selectedItem < 0)
		{
			selectedItem = 5;
		}
	}
}

void Menu::MoveDown()
{
	++selectedItem;
	if (option == MAIN)
	{
		if (selectedItem > 2)
		{
			selectedItem = 0;
		}
	}
	else if(option == OPTIONS) {
		if (selectedItem > 5)
		{
			selectedItem = 0;
		}
	}
}

void Menu::CheckEvents(sf::Event ev, sf::RenderWindow *& window, Game_State & state, std::map<std::string, sf::Keyboard::Key> & keys)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (option == MAIN)
		{
			switch (ev.key.code)
			{
			case sf::Keyboard::Up:
				MoveUp();
				break;
			case sf::Keyboard::Down:
				MoveDown();
				break;
			case sf::Keyboard::Enter:
				switch (selectedItem)
				{
				case 0:
					state = PLAYING;
					break;
				case 1:
					option = OPTIONS;
					selectedItem = 0;
					break;
				case 2:
					window->close();
					break;
				}

			}
		}
		else if (option == OPTIONS)
		{
			switch (ev.key.code)
			{
			    case sf::Keyboard::Escape:
					selectedItem = 0;
					option = MAIN;
					break;
				case sf::Keyboard::Down:
					MoveDown();
					break;
				case sf::Keyboard::Up:
					MoveUp();
					break;
				case sf::Keyboard::Enter:
					BindKeys(keys, *window);

						for (int i = 5; i >= 0; --i)
						{
							//KeysText[i].setOrigin(KeysText[i].getLocalBounds().left / 2.0f, KeysText[i].getLocalBounds().height / 2.0f);
							//KeysText[i].setPosition(menu[i+3].getLocalBounds().width + KeysText[i].getLocalBounds().width, menu[i+3].getLocalBounds().height);
						}
					break;
					
			}
		}
	}
	
}

void Menu::BindKeys(std::map<std::string, sf::Keyboard::Key>& keys, sf::RenderWindow & window)
{
	sf::Event bind;
	std::cout << sf::Keyboard::A << "\n";
	int x;
	std::string w;
	switch (selectedItem)
	{
	case 0:

		break;
	case 1:
		x = set_Key(keys, window, "MOVEUP");
		w = exchange_key_code_to_string(x);
		KeysText[0].setString(w);
		std::cout << x << " " << exchange_key_code_to_string(x);
		break;
	case 2:
		x = set_Key(keys, window, "MOVEDOWN");
		w = exchange_key_code_to_string(x);
		KeysText[1].setString(w);
		break;

	case 3:
		x = set_Key(keys, window, "MOVELEFT");
		w = exchange_key_code_to_string(x);
		KeysText[2].setString(w);
		break;

	case 4:
		x = set_Key(keys, window, "MOVERIGHT");
		w = exchange_key_code_to_string(x);
		KeysText[3].setString(w);
		break;

	case 5:
		x = set_Key(keys, window, "SHOOT");
		w = exchange_key_code_to_string(x);
		KeysText[4].setString(w);
		break;
	}
}

int Menu::set_Key(std::map<std::string, sf::Keyboard::Key>& keys, sf::RenderWindow & window, const char * name)
{
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{

			keys[name] = event.key.code;
			return event.key.code;

		}
	}


}

void Menu::Draw(sf::RenderWindow & window, float height, float width)
{
	if (option == MAIN)
	{
		for (int i = 2; i >= 0; --i)
		{
			window.draw(menu[i]);
		}
		switch (selectedItem)
		{
		case 0:
			select_sprite.setPosition(menu[0].getPosition().x - 25, menu[0].getPosition().y);
			window.draw(select_sprite);
			break;
		case 1:
			select_sprite.setPosition(menu[1].getPosition().x - 25, menu[1].getPosition().y);
			window.draw(select_sprite);
			break;
		case 2:
			select_sprite.setPosition(menu[2].getPosition().x - 25, menu[2].getPosition().y);
			window.draw(select_sprite);
			break;
		}
	}
	else if (option == OPTIONS)
	{
		for (int i = 8; i >= 3; --i)
		{
			window.draw(menu[i]);
			window.draw(KeysText[i-3]); // [5, 0]
		}
		
		
		switch (selectedItem)
		{
		case 0:
			select_sprite.setPosition(menu[3].getPosition().x - 25, menu[3].getPosition().y);
			window.draw(select_sprite);
			break;
		case 1:
			select_sprite.setPosition(menu[4].getPosition().x - 25, menu[4].getPosition().y); //Move UP
			
			window.draw(select_sprite);
			break;
		case 2:
			select_sprite.setPosition(menu[5].getPosition().x - 25, menu[5].getPosition().y);
			window.draw(select_sprite);
			break;
		case 3:
			select_sprite.setPosition(menu[6].getPosition().x - 25, menu[6].getPosition().y);
			window.draw(select_sprite);
			break;
		case 4:
			select_sprite.setPosition(menu[7].getPosition().x - 25, menu[7].getPosition().y);
			window.draw(select_sprite);
			break;
		case 5:
			select_sprite.setPosition(menu[8].getPosition().x - 25, menu[8].getPosition().y);
			window.draw(select_sprite);
			break;

		}
	}
}

std::string Menu::exchange_key_code_to_string(int KeyCode)
{
	std::string key_name;
	switch (KeyCode)
	{
	case sf::Keyboard::Q:
		key_name = "Q";
		break;
	case sf::Keyboard::W:
		key_name = "W";
		break;
	case sf::Keyboard::E:
		key_name = "E";
		break;
	case sf::Keyboard::R:
		key_name = "R";
		break;
	case sf::Keyboard::T:
		key_name = "T";
		break;
	case sf::Keyboard::Y:
		key_name = "Y";
		break;
	case sf::Keyboard::U:
		key_name = "U";
		break;
	case sf::Keyboard::I:
		key_name = "I";
		break;
	case sf::Keyboard::O:
		key_name = "O";
		break;
	case sf::Keyboard::P:
		key_name = "P";
		break;
	case sf::Keyboard::A:
		key_name = "A";
		break;
	case sf::Keyboard::S:
		key_name = "S";
		break;
	case sf::Keyboard::D:
		key_name = "D";
		break;
	case sf::Keyboard::F:
		key_name = "F";
		break;
	case sf::Keyboard::G:
		key_name = "G";
		break;
	case sf::Keyboard::H:
		key_name = "H";
		break;
	case sf::Keyboard::J:
		key_name = "J";
		break;
	case sf::Keyboard::K:
		key_name = "K";
		break;
	case sf::Keyboard::L:
		key_name = "L";
		break;
	case sf::Keyboard::Z:
		key_name = "Z";
		break;
	case sf::Keyboard::X:
		key_name = "X";
		break;
	case sf::Keyboard::C:
		key_name = "C";
		break;
	case sf::Keyboard::V:
		key_name = "V";
		break;
	case sf::Keyboard::B:
		key_name = "B";
		break;
	case sf::Keyboard::N:
		key_name = "N";
		break;
	case sf::Keyboard::M:
		key_name = "M";
		break;
	case sf::Keyboard::Up:
		key_name = "UP";
		break;
	case sf::Keyboard::Down:
		key_name = "DOWN";
		break;
	case sf::Keyboard::Left:
		key_name = "LEFT";
		break;
	case sf::Keyboard::Right:
		key_name = "RIGHT";
		break;
	case sf::Keyboard::Comma:
		key_name = ",";
		break;
	}
	return key_name;
}


