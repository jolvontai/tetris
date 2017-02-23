#pragma once
#include"renderer.h"
#include"game.h"
#include"fileloader.h"
#include"math.hpp"
#include"inputmanager.h"

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
	FileLoader* fLoader;
	InputManager inputManager;

	gameStates currentState;
	Game* game;

};