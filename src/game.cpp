#include "game.h"


Game::Game()
{

}

std::vector<Element2D*>* Game::Init()
{
	gameObjects.push_back(new Rect(-0.8f, 0.8f, 0.3f, 0.3f));
	gameObjects.push_back(new Rect(0.5f, 0.5f, 0.4f, 0.4f));
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
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}
