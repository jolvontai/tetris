#pragma once


#include<GL/glew.h>
#include<SDL2/SDL.h>
#include<vector>


#include"shader.h"
#include"element2d.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	bool Init();
	void Render();
	bool CreateWindow();
	void SettoRender(std::vector<Element2D*>* objects);
	void SetObjCol(Element2D* object,
		GLfloat r, GLfloat g,
		GLfloat b, GLfloat a);
	
private:
	bool SetOpenGLAttributes();
	Shader* shader;
	SDL_GLContext sdlContent;
	SDL_Window* gameWindow;
	std::vector<Element2D*>* toRender;
};