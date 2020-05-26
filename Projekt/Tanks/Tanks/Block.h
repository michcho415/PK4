#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"
#include "SFML/Graphics.hpp"


enum Block_type {NONE, BRICK, METAL, BUSH};

class Block: public Object
{
	Block_type bl_type;
	
public:
	Block();
	Block(float x, float y); 
	void set_Tile();
	void Draw(sf::RenderWindow *& window);
	void setSprite(Block_type type);
	void Update(sf::Event & ev, float dt);
	void shape_Sprite(sf::IntRect & x);
	Block_type get_block_type() { return bl_type; }

};


#endif
