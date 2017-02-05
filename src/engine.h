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
	void Render();
	
private:
	void Update();
	
	enum gameStates {
		RUNNING,
		LOADING,
		CHANGE_SCENE,
		EXIT
	};
	Renderer* renderer;

	gameStates currentState;
	Game* game;

};