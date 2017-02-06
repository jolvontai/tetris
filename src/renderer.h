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
	bool Init();
	void Render();
	bool CreateWindow();
	void SettoRender(std::vector<Element2D*>* objects);
	
private:
	bool SetOpenGLAttributes();
	GLchar* vertexShaderSource;
	GLchar* fragmentShaderSource;
	GLuint shaderProgram = 0;
	SDL_GLContext sdlContent;
	SDL_Window* gameWindow;
	std::vector<Element2D*>* toRender;
};