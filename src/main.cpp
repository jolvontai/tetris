

//C++ Headers
#include <string>
#include <iostream>



//Game files
#include "engine.h"
#include "renderer.h"
#include "game.h"


int main(int argc, char *argv[])
{
	
	Engine engine;
	if (!engine.Init())
	{
		std::cout << "failed to initialize engine \n";
		return 0;
	}
	Game * game = new Game();
	if (!engine.Load(game))
	{
		std::cout << "failed to load game \n";
	}
	engine.Launch();


	return 0;
}


