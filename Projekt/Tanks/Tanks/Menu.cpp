#include "Menu.h"

Menu::Menu(float height, float width):selectedItem(0), option(MAIN_MENU)
{
	
	tex.loadFromFile("Resources/Player1.bmp", sf::IntRect(30, 30, 30, 30));
	select_sprite.setTexture(tex);
	select_sprite.setOrigin(select_sprite.getLocalBounds().width/ 2.0f, select_sprite.getLocalBounds().height/2.0f);
	int x = select_sprite.getOrigin().x;
	if (!font.loadFromFile("Resources/NesFont.ttf"))
	{

	}


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

	for (int i = 8; i >= 0; --i)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(15);
		menu[i].setOrigin(menu[i].getLocalBounds().left / 2.0f, menu[i].getLocalBounds().height / 2.0f);
	}

}

void Menu::MoveUp()
{
	--selectedItem;
	if (option == MAIN_MENU)
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
	if (option == MAIN_MENU)
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

void Menu::CheckEvents(sf::Event ev, sf::RenderWindow & window)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (option == MAIN_MENU)
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
					//TO DO: startuj gre
					break;
				case 1:
					option = OPTIONS;
					selectedItem = 0;
					break;
				case 2:
					window.close();
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
					option = MAIN_MENU;
					break;
				case sf::Keyboard::Down:
					MoveDown();
					break;
				case sf::Keyboard::Up:
					MoveUp();
					break;
				case sf::Keyboard::Enter:
					switch (selectedItem)
					{
					case 0:

						break;
					case 1:

						break;
					}
			}
		}
	}
	
}

void Menu::Draw(sf::RenderWindow & window, float height, float width)
{
	if (option == MAIN_MENU)
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
		}
		switch (selectedItem)
		{
		case 0:
			select_sprite.setPosition(menu[3].getPosition().x - 25, menu[3].getPosition().y);
			window.draw(select_sprite);
			break;
		case 1:
			select_sprite.setPosition(menu[4].getPosition().x - 25, menu[4].getPosition().y);
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
