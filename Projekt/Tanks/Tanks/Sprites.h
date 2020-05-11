#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>

class Sprites
{
	std::map<std::string, sf::Texture> textures;

public:
	sf::Sprite get_sprite(const std::string & name, sf::IntRect x);
	
	Sprites();
	Sprites(const Sprites & o) = delete;
	static Sprites & Get() { static Sprites sprites; return sprites; };


};


#endif