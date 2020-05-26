#ifndef TEMPLATES_H
#define TEMPLATES_H
#include "SFML/Graphics.hpp"
#include "Level.h"

template<class T>
void CenterOrigin(T & t)
{
	t.setOrigin(t.getLocalBounds().width / 2.0f, t.getLocalBounds().height/2.0f);
}

template<class T>
void CenterPosition_X(T & t, sf::RenderWindow *& window, float y)
{
	t.setPosition(window->getSize().x/2.0f, y);
}

template<class T>
void SetPositionfromCenter(T & t, sf::RenderWindow *& window, float x, float y)
{
	t.setPosition(window->getSize().x / 2.0f + x, window->getSize().y / 2.0f + y);
}

#endif
