#include "Level.h"
#include "OriginandPositionTemplate.h"
#include "Game.h"
#include "Sprites.h"
#include <fstream>

void Level::LoadLevelfromFile(const std::string & filename) // dodac switch
{
	std::ifstream input(R"(Stages\)" + filename);
	int block_type;
	float background_x = square.getGlobalBounds().left;
	float background_y = square.getGlobalBounds().top;
	if (input.is_open())
	{
		for (size_t i = 0; i < data.size(); ++i)
		{
			for (size_t j = 0; j < data[i].size(); ++j)
			{
				input >> block_type;
				input.get();
				Block block(background_x + (j * 16.0f) + 8, background_y + i * 16.0f + 8);
				if (block_type == 0) {
					block.setSprite(NONE);
				}
				else if (block_type == 1) {
					block.setSprite(BRICK);
				}
				else if (block_type == 2){
					block.setSprite(METAL);
				}
				else{
					block.setSprite(BUSH);
				}
				data[i][j] = block;

			}

		}
	}
	input.close();
}

Level::Level(sf::RenderWindow *& window)
{
	square.setSize(sf::Vector2f(416.f,416.f));
	square.setFillColor(sf::Color::Black);
	CenterOrigin(square);
	//SetPositionfromCenter(square, window, -square.getLocalBounds().height/2-60, -square.getLocalBounds().width/2);
	SetPositionfromCenter(square, window, square.getLocalBounds().top / 2 - 60, square.getLocalBounds().left / 2);

}

void Level::Draw(sf::RenderWindow *& window)
{

	for (size_t i = 0; i < data.size() ; ++i)
	{
		for (size_t j = 0; j < data[i].size(); ++j)
		{
			if (data[i][j].get_block_type() != NONE)
			{
				data[i][j].Draw(window);
			}
		}
		
	}
}

float Level::get_Center_y()
{
	return square.getPosition().y;
}

void Level::Draw_background(sf::RenderWindow *& window)
{
	window->draw(square);
}

const float Level::get_size_x() const
{
	return square.getSize().x;
}

const float Level::get_size_y() const
{
	return square.getSize().y;
}

Block Level::get_block(int x, int y)
{
	return data[y][x];
}

void Level::set_block(int x, int y, Block_type type)
{
	data[y][x].setSprite(type);
}

float Level::get_Center_x()
{
	return square.getPosition().x;
}


