#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>

///Klasa przechowuj�ca tekstury (singleton)
class Sprites
{
	std::map<std::string, sf::Texture> textures; ///mapa tekstur

public:

	/** Metoda pozwala uzyska� odpowiedniego sprite'a z tekstury
	@param name klucz pod kt�rym jest tekstura
	@param x kt�ry wycinek tekstury
	@return zwraca sprite'a
	*/
	sf::Sprite Get_sprite(const std::string & name, sf::IntRect x);

	Sprites();
	Sprites(const Sprites & o) = delete;
	static Sprites & Get() { static Sprites sprites; return sprites; };


};


#endif