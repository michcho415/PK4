#ifndef LEVEL_H
#define LEVEL_H
#include "SFML/Graphics.hpp"
#include <array>
#include "Object.h"
#include "Block.h"

class Level
{
	sf::RectangleShape square;
	const static size_t size_x = 26;
	const static size_t size_y = 26;
	

	std::array<std::array<Block, size_x>, size_y> data;



public:
	void LoadLevelfromFile(const std::string & filename);
	Level(sf::RenderWindow *& window);
	void Draw(sf::RenderWindow *& window);
	

};

#endif
