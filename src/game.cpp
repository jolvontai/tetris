#include "game.h"


Game::Game()
{

}

std::vector<Element2D*>* Game::Init()
{
	Rect* cube = new Rect();
	gameObjects.push_back(cube);
	return &gameObjects;
}
void Game::HandleInput()
{

}
void Game::Update()
{

}
void Game::Render()
{

	
}
void Game::Start()
{
	this->Init();
}

/*void Game::CheckSDLError(int line = -1)
{
	std::string error = SDL_GetError();

	if (error != "")
	{
		std::cout << "SLD Error : " << error << std::endl;

		if (line != -1)
			std::cout << "\nLine : " << line << std::endl;

		SDL_ClearError();
	}
}*/

Game::~Game()
{
}
