#include "Block.h"
#include "Sprites.h"
#include "OriginandPositionTemplate.h"

Block::Block(): Object(), bl_type(NONE)
{
}

Block::Block(double x, double y) : Object(x, y, 0, UP_)
{
	size = 16;
}

int Block::Get_size()
{
	return size;
}

void Block::Set_tile()
{
	tile_x = (x - 52) / 16;
	tile_y = (y - 32) / 16;
}

void Block::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Block::Set_sprite(Block_type type)
{
	bl_type = type;
	switch (type)
	{
	case BRICK:
		sprite = Sprites::Get().Get_sprite("Blocks", sf::IntRect(0, 0, 16, 16));
		break;
	case METAL:
		sprite = Sprites::Get().Get_sprite("Blocks", sf::IntRect(224, 0, 16, 16));
		break;
	case BUSH:
		sprite = Sprites::Get().Get_sprite("Blocks", sf::IntRect(208, 0, 16, 16));
		break;

	}
	CenterOrigin(sprite);
	sprite.setPosition(x, y);
}

void Block::Update(sf::Event & ev, double dt)
{

}


