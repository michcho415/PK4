
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Menu.h"
#include "Game.h"
#include "vld.h"

int main()
{
	
	try {
		
		Game::Get().Run();
	}
	catch (...)
	{
		return 0;
	}

	return 0;
}