#include"game.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

Game::Game()
{
}

std::vector<Element2D*>* Game::Init()
{
	gameObjects.push_back(new Rect(0.5f, 0.5f, 100.0f, 100.0f,1));
	std::function<void()> f = std::bind(&Rect::Biggen, (Rect*)gameObjects[0]);
	If::Register(SDLK_DOWN,std::bind(&Rect::Smallen, (Rect*)gameObjects[0]));
	If::Register(SDLK_UP,f);
	If::Register(SDLK_LEFT,std::bind(&Rect::RotateL, (Rect*)gameObjects[0]));
	If::Register(SDLK_RIGHT,std::bind(&Rect::MoveR, (Rect*)gameObjects[0]));
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
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}
