#pragma once
#include"renderer.h"
#include"game.h"


class Engine
{
public:
	Engine();
	~Engine();
	bool Init();
	bool Load(Game* game);
	void Launch();
	void Update();
	void Render();
private:
	Renderer* renderer;
	Game* game;

};