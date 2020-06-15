#include <map>
#include "Sprites.h"

sf::Sprite Sprites::Get_sprite(const std::string & name, sf::IntRect x)
{
	return 	sf::Sprite(textures[name], x);
}


Sprites::Sprites()
{
	if (!textures["Tanks"].loadFromFile("Resources/tank.png"))
	{
		throw "sth"; // TO DO: rzuc wyjatkiem: nieudalo sie odczytac z pliku
	}
	if (!textures["Blocks"].loadFromFile("Resources/block.png"))
	{
		throw "sth";
	}
	if (!textures["Title"].loadFromFile("Resources/Title.png"))
	{
		throw "sth";
	}
	if (!textures["Bullets"].loadFromFile("Resources/Bullets.png"))
	{
		throw "sth";
	}

}
