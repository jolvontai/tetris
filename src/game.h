#pragma once


#include <string>
#include <iostream>

#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "game.h"

class Game
{
public:
	Game();
	~Game();

	bool Init();
	void HandleInput();
	void Update();
	void Render();
	void Start();
	void CheckSDLError(int line);

private:
	SDL_Window * gameWindow;
	SDL_GLContext content;
	bool SetOpenGLAttributes();

};
