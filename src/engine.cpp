#pragma once
#include "engine.h"

Engine::Engine()
{
	renderer = new Renderer();
}
bool Engine::Init()
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to init SDL\n";
		return false;
	}
	if (!renderer->Init())
	{
		return false;
	}
	renderer->CreateWindow();
	currentState = gameStates::LOADING;
	return true;

}
bool Engine::Load(Game* game)
{
	this->game = game;
	std::vector<Element2D*>* objects = game->Init();
	if (objects->size() == 0)
	{
		return false;
	}
	renderer->SettoRender(objects);
	return true;
}
void Engine::Launch()
{
	currentState = gameStates::RUNNING;
	Update();

}
void Engine::Update()
{
	SDL_Event event;
	while (currentState == gameStates::RUNNING)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				currentState = gameStates::EXIT;
			}
		}
		game->Update();
		renderer->Render();
	}
}

Engine::~Engine()
{
	delete game;
}
