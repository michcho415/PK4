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
	

	std::array<std::array<Block, size_x>, size_y+1> data; //vector?



public:
	void LoadLevelfromFile(const std::string & filename);
	Level(sf::RenderWindow *& window);
	void Draw(sf::RenderWindow *& window);
	float get_Center_x();
	float get_Center_y();
	void Draw_background(sf::RenderWindow *& window);
	const static size_t get_size_x() { return size_x; }
	const static size_t get_size_y() { return size_y; }
	Block get_block(int x, int y);
	void set_block(int x, int y, Block_type type);




};

#endif
