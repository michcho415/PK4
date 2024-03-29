#include "Menu.h"
#include "Game.h"
#include "Sprites.h"
#include <sstream>



void Menu::Init()
{
	select_sprite = Sprites::Get().Get_sprite("Tanks", sf::IntRect(0, 30, 30, 30));
	Title = Sprites::Get().Get_sprite("Title", sf::IntRect(0, 0, 357, 151));

	if (!tex.loadFromFile("Resources/Player1.bmp", sf::IntRect(0, 30, 30, 30)))
	{
		throw "Nie udalo sie odczytac pliku Player1.bmp!";
	}
	if (!font.loadFromFile("Resources/NesFont.ttf"))
	{
		throw "Nie udalo sie odczytac pliku NesFont.ttf!";
	}
	if (!title.loadFromFile("Resources/Title.png"))
	{
		throw "Nie udalo sie odczytac pliku Title.png!";
	}
}

Menu::Menu(sf::RenderWindow *& window):selectedItem(0)
{

	Init();
	Title.setTexture(title);
	CenterOrigin(Title);
	CenterPosition_X(Title, window, 150);
	CenterOrigin(select_sprite);

	//MAIN MENU
	menu[0].setString("PLAY");
	menu[1].setString("OPTIONS");
	menu[2].setString("EXIT");
		
	menu[3].setString("DIFFICULTY: ");
	menu[4].setString("MOVE UP: ");
	menu[5].setString("MOVE DOWN: ");
	menu[6].setString("MOVE LEFT: ");
	menu[7].setString("MOVE RIGHT: ");
	menu[8].setString("SHOOT: ");

	////default Keys
	KeysText[0].setString("EASY");
	KeysText[1].setString("UP");
	KeysText[2].setString("DOWN");
	KeysText[3].setString("LEFT");
	KeysText[4].setString("RIGHT");
	KeysText[5].setString("SPACE");
	press_key.setString("PRESS KEY!");
	Init_text_box(press_key);
	SetPositionfromCenter(press_key, window, 0, 120);
	press_key.setFont(font);
	press_key.setCharacterSize(15);

	//mainmenu
	for (int i = 0; i <= 8; ++i)
	{
		Init_text_box(menu[i]);
		Init_text_box(KeysText[i]);
		CenterPosition_X(menu[i], window, window->getSize().x / 2.0f + 30*i);
	}
	//options
	for (int i = 3; i <= 8; ++i)
	{
		SetPositionfromCenter(menu[i], window, -45.0f, -160.0f + 30.0f * i);
		SetPositionfromCenter(KeysText[i-3], window, 80.0f, -160.0f + 30.0f * i);
	}
	//UI
	PointsText.setFont(font);
	PointsText.setCharacterSize(10);
	PointsText.setString("POINTS");
	Score.setFont(font);
	Score.setCharacterSize(10);
	GameOver.setString("GAME OVER");
	Init_text_box(GameOver);
	SetPositionfromCenter(GameOver, window, 0, 0);

	CenterOrigin(PointsText);
	SetPositionfromCenter(PointsText, window, 232, -200); 
	SetPositionfromCenter(Score, window, 232, -180);


	

}

void Menu::Init_text_box(sf::Text & text_box)
{
	text_box.setFont(font);
	text_box.setCharacterSize(15);
	CenterOrigin(text_box);
}

void Menu::MoveUp()
{
	--selectedItem;
	if (Game::Get().Get_game_state() == MAIN_MENU)
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
	if (Game::Get().Get_game_state() == MAIN_MENU)
	{
		if (selectedItem > 2)
		{
			selectedItem = 0;
		}
	}
	else //if(option == OPTIONS)
	{
		if (selectedItem > 5)
		{
			selectedItem = 0;
		}
	}
}

void Menu::CheckEvents(sf::Event ev, sf::RenderWindow *& window, std::map<Keys, sf::Keyboard::Key> & keys)
{
	
	if (ev.type == sf::Event::KeyPressed)
	{
		if (Game::Get().Get_game_state() == MAIN_MENU)
		{
			if (ev.key.code == keys[UP])
			{
				MoveUp();
			}
			else if (ev.key.code == keys[DOWN])
			{
				MoveDown();
			}
			else if (ev.key.code == keys[ENTER])
			{
			switch (selectedItem)
			{
			case 0:
				Game::Get().Set_game_state(PLAYING);
				break;
			case 1:
				Game::Get().Set_game_state(OPTIONS);
				//option = OPTIONS;
				selectedItem = 0;
				break;
			case 2:
				window->close();
				break;
			}
			}
		}
		else if (Game::Get().Get_game_state() == OPTIONS)
		{
			if (ev.key.code == keys[ESCAPE])
			{
				selectedItem = 0;
				Game::Get().Set_game_state(MAIN_MENU);
			}
			else if (ev.key.code == keys[UP])
			{
				MoveUp();
			}
			else if (ev.key.code == keys[DOWN])
			{
				MoveDown();
			}
			else if (ev.key.code == keys[ENTER])
			{
				BindKeysandChangeDifficulty(keys, window);
			}
		}
	}
	
}

void Menu::BindKeysandChangeDifficulty(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window)
{
	int x;
	std::string w;


	switch (selectedItem)
	{
	case 0:
		if (Game::Get().Get_difficulty() == EASY)
		{
			Game::Get().Set_difficulty(MEDIUM);
			KeysText[0].setString("MEDIUM");
		}
		else if (Game::Get().Get_difficulty() == MEDIUM)
		{
			Game::Get().Set_difficulty(HARD);
			KeysText[0].setString("HARD");
		}
		else {
			Game::Get().Set_difficulty(EASY);
			KeysText[0].setString("EASY");
		}
		
		break;
	case 1:
		
		x = set_Key(keys, window, UP);
		w = exchange_key_code_to_string(x);
		KeysText[1].setString(w);
		break;
	case 2:
		x = set_Key(keys, window, DOWN);
		w = exchange_key_code_to_string(x);
		KeysText[2].setString(w);
		break;

	case 3:
		x = set_Key(keys, window, LEFT);
		w = exchange_key_code_to_string(x);
		KeysText[3].setString(w);
		break;

	case 4:
		x = set_Key(keys, window, RIGHT);
		w = exchange_key_code_to_string(x);
		KeysText[4].setString(w);
		break;

	case 5:
		x = set_Key(keys, window, SHOOT);
		w = exchange_key_code_to_string(x);
		KeysText[5].setString(w);
		break;
	}
}

int Menu::set_Key(std::map<Keys, sf::Keyboard::Key>& keys, sf::RenderWindow *& window, enum Keys id)
{
	sf::Event event;

		window->draw(press_key);
		window->display();
		while (window->waitEvent(event))
		{

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
				{
					return sf::Keyboard::Unknown;
				}
				keys[id] = event.key.code;
				return event.key.code;

			}

		}
	
	return -1;


}

void Menu::Draw(sf::RenderWindow *& window)
{
	if (Game::Get().Get_game_state() == MAIN_MENU)
	{
		window->draw(Title);
		for (int i = 2; i >= 0; --i)
		{
			window->draw(menu[i]);
		}
		switch (selectedItem)
		{
		case 0:
			select_sprite.setPosition(menu[0].getPosition().x - 80, menu[0].getPosition().y);
			window->draw(select_sprite);
			break;
		case 1:
			select_sprite.setPosition(menu[1].getPosition().x - 80, menu[1].getPosition().y);
			window->draw(select_sprite);
			break;
		case 2:
			select_sprite.setPosition(menu[2].getPosition().x - 80, menu[2].getPosition().y);
			window->draw(select_sprite);
			break;
		}
	}
	else if (Game::Get().Get_game_state() == OPTIONS)
	{
		for (int i = 8; i >= 3; --i)
		{
			window->draw(menu[i]);
			window->draw(KeysText[i-3]); // [5, 0]
		}
		
		
		switch (selectedItem)
		{
		case 0:
			select_sprite.setPosition(menu[3].getPosition().x - 120, menu[3].getPosition().y);
			window->draw(select_sprite);
			break;
		case 1:
			select_sprite.setPosition(menu[4].getPosition().x - 120, menu[4].getPosition().y); //Move UP
			
			window->draw(select_sprite);
			break;
		case 2:
			select_sprite.setPosition(menu[5].getPosition().x - 120, menu[5].getPosition().y);
			window->draw(select_sprite);
			break;
		case 3:
			select_sprite.setPosition(menu[6].getPosition().x - 120, menu[6].getPosition().y);
			window->draw(select_sprite);
			break;
		case 4:
			select_sprite.setPosition(menu[7].getPosition().x - 120, menu[7].getPosition().y);
			window->draw(select_sprite);
			break;
		case 5:
			select_sprite.setPosition(menu[8].getPosition().x - 120, menu[8].getPosition().y);
			window->draw(select_sprite);
			break;

		}
	}
	else if (Game::Get().Get_game_state() == PLAYING)
	{
		Exchange_points_to_text();
		window->draw(PointsText);
		window->draw(Score);
	}
	else if (Game::Get().Get_game_state() == OVER)
	{
		window->draw(GameOver);
		PointsText.setString("Your Score:");
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
	case sf::Keyboard::Space:
		key_name = "SPACE";
		break;
	default:
		key_name = "UNKNOWN!";
		break;

	}
	return key_name;
}

std::string Menu::Difficulty_to_string(Difficulty diff)
{
	std::string word;
	switch (diff)
	{
	case EASY:
		word = "EASY";
		break;
	case MEDIUM:
		word = "MEDIUM";
		break;
	case HARD:
		word = "HARD";
		break;
	}
	return word;

}

void Menu::Exchange_points_to_text()
{
	std::stringstream s;
	s << Game::Get().Get_score();
	Score.setString(s.str());
	CenterOrigin(Score);
}
