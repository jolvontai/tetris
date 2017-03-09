#pragma once

#include"renderer.h"

#include"fileloader.h"
#include"math.hpp"
#include"inputmanager.h"


class Game;
class Engine
{
public:
	Engine();
	~Engine();
	bool Init();
	bool Load(Game* game);
	void Launch();
	void Render();
	InputManager inputManager;
	
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
	

	gameStates currentState;
	Game* game;

};
#include"game.h"
#include"interface.h"