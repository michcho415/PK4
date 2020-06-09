#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Game.h"

int main()
{
	
	try {
		std::cout << ((6 + 1 + 1) % 5) + 1 << '\n';
		Game::Get().Run();
	}
	catch (...)
	{
		return 0;
	}

	return 0;
}