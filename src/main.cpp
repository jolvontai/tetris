// Headerphile.com OpenGL Tutorial part 1
// A Hello World in the world of OpenGL ( creating a simple windonw and setting background color )
// Source code is an C++ adaption / simplicication of : https://www.opengl.org/wiki/Tutorial1:_Creating_a_Cross_Platform_OpenGL_3.2_Context_in_SDL_(C_/_SDL)
// Compile : clang++ main.cpp -lGL -lSDL2 -std=c++11 -o Test

// C++ Headers
#include <string>
#include <iostream>



//Game files
#include "engine.h"
#include "renderer.h"
#include "game.h"


int main(int argc, char *argv[])
{
	Game * game = new Game();
	Engine engine;
	if (!engine.Init())
	{
		std::cout << "failed to initialize engine \n";
		return 0;
	}
	if (!engine.Load(game))
	{
		std::cout << "failed to load game \n";
	}
	if (!game->Init())
		return 0;
	game->Update();


	return 0;
}


