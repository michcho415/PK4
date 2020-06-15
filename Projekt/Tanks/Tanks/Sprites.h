#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>

/**Klasa przechowujaca tekstury (singleton)*/
class Sprites
{
	/**mapa tekstur*/
	std::map<std::string, sf::Texture> textures; 

public:

	/** Metoda pozwala uzyskac odpowiedniego sprite'a z tekstury
	@param name klucz pod ktorym jest tekstura
	@param x ktory wycinek tekstury
	@return zwraca sprite'a
	*/
	sf::Sprite Get_sprite(const std::string & name, sf::IntRect x);

	Sprites();
	Sprites(const Sprites & o) = delete;
	static Sprites & Get() { static Sprites sprites; return sprites; };


};


#endif