#pragma once
#include "engine.h"

Engine::Engine()
{

}
bool Engine::Init()
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to init SDL\n";
		return false;
	}
	renderer = new Renderer();
	renderer->CreateWindow();
	return true;

}
bool Engine::Load(Game* game)
{
	this->game = game;
	if (!game->Init())
	{
		this->game = nullptr;
		return false;
	}
	return true;
}
void Engine::Launch()
{
}
void Engine::Update()
{
	game->Update();
	renderer->Render();
}

Engine::~Engine()
{
	delete game;
}
