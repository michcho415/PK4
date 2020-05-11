#include "Block.h"
#include "Sprites.h"

Block::Block(): Object()
{
}

Block::Block(float x, float y): Object(x, y, 0), type(type)
{
}

void Block::Draw(sf::RenderWindow *& window)
{
	window->draw(sprite);
}

void Block::setSprite(Block_type type)
{
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
	sprite.setPosition(x, y);
}

void Block::Update()
{
}
