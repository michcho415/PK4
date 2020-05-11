#include "Level.h"
#include "OriginandPositionTemplate.h"
#include "Game.h"
#include "Sprites.h"
#include <fstream>

void Level::LoadLevelfromFile(const std::string & filename)
{
	std::ifstream input(R"(Stages\)" + filename);
	int block_type;
	float background_x = square.getPosition().x;
	float background_y = square.getPosition().y;
	//unsigned int b_size;
	//b_size = Game::Get().get_block_size();
	if (input.is_open())
	{
		for (size_t i = 0; i < data.size(); ++i)
		{
			for (size_t j = 0; j < data[i].size(); ++j)
			{
				input >> block_type;
				input.get();
				Block block(background_x + (j * 16.0f), background_y + i * 16.0f);
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
	SetPositionfromCenter(square, window, -square.getLocalBounds().height/2-60, -square.getLocalBounds().width/2);

}

void Level::Draw(sf::RenderWindow *& window)
{
	window->draw(square);
	for (size_t i = 0; i < data.size() ; ++i)
	{
		for (size_t j = 0; j < data[i].size(); ++j)
		{
			data[i][j].Draw(window);
		}
		
	}
}

