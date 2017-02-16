#include "game.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
Game::Game()
{

}

std::vector<Element2D*>* Game::Init()
{
	gameObjects.push_back(new Rect(-0.8f, 0.8f, 0.3f, 0.3f,1));
	gameObjects.push_back(new Rect(0.0f, 0.0f, 0.2f, 0.2f,1));

	gameObjects.back()->transform.rotate(90.0f,Vector2(0.0f,0.0f));
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
