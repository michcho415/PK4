#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
#include "SFML/Graphics.hpp"


enum Block_type {NONE, BRICK, METAL, BUSH};

class Block: public Object
{
	int size;
	Block_type bl_type;
	
public:
	Block();
	Block(double x, double y);
	int get_size();
	void set_Tile();
	void Draw(sf::RenderWindow *& window);
	void setSprite(Block_type type);
	void Update(sf::Event & ev, double dt);
	Block_type get_block_type() { return bl_type; }

};


#endif
