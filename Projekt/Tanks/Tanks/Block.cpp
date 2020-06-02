#include "Block.h"
#include "Sprites.h"
#include "OriginandPositionTemplate.h"

Block::Block(): Object(), bl_type(NONE)
{
}

Block::Block(float x, float y) : Object(x, y, 0, UP_)
{
	size = 8;
}

int Block::get_size()
{
	return size;
}

void Block::set_Tile()
{
}

void Block::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Block::setSprite(Block_type type)
{
	bl_type = type;
	switch (type)
	{
	case BRICK:
		sprite = Sprites::Get().get_sprite("Blocks", sf::IntRect(0, 0, 16, 16));
		break;
	case METAL:
		sprite = Sprites::Get().get_sprite("Blocks", sf::IntRect(224, 0, 16, 16));
		break;
	case BUSH:
		sprite = Sprites::Get().get_sprite("Blocks", sf::IntRect(208, 0, 16, 16));
		break;

	}
	CenterOrigin(sprite);
	sprite.setPosition(x, y);
}

void Block::Update(sf::Event & ev, float dt)
{

}

void Block::shape_Sprite(sf::IntRect & x)
{
}
