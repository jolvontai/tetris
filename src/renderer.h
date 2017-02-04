#pragma once
#include "element2d.h"
#include<GL\glew.h>
#include<SDL2\SDL.h>
#include<vector>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Render();
	bool CreateWindow();
private:
	bool SetOpenGLAttributes();
	SDL_GLContext sdlContent;
	SDL_Window* gameWindow;
	std::vector<Element2D*> toRender;
};