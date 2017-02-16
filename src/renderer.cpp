#include "renderer.h"
#include<iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer()
{
	SetOpenGLAttributes();
	toRender = nullptr;
}
bool Renderer::Init()
{
	gameWindow = SDL_CreateWindow("testi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL);
	if (!gameWindow)
		return false;
	this->sdlContent = SDL_GL_CreateContext(gameWindow);
	glewExperimental = GL_TRUE;
	glewInit();
	shader = new Shader("src/shaders/shader.vs",
		"src/shaders/shader.frag");
	return true;
	
}

Renderer::~Renderer()
{
	delete shader;
	toRender = nullptr;
	delete toRender;
	SDL_GL_DeleteContext(sdlContent);
	SDL_DestroyWindow(gameWindow);
	SDL_Quit();

}
void Renderer::Render()
{
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	shader->use();
	for (int i = 0; i < toRender->size();i++)
	{
		toRender->at(i)->transform.rotation += 0.5f;
		Vector2 temp = toRender->at(i)->transform.GetScale();
		GLuint transformLoc = glGetUniformLocation(shader->program, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, toRender->at(i)->transform.GetTransformation());
		toRender->at(i)->render();
	}
	SDL_GL_SwapWindow(gameWindow);
}

bool Renderer::CreateWindow()
{

	SDL_GL_SetSwapInterval(1);
	return true;
}

void Renderer::SettoRender(std::vector<Element2D*>* objects)
{
	this->toRender = objects;
}
void Renderer::SetObjCol(Element2D* object, GLfloat r,GLfloat g,GLfloat b,GLfloat a)
{
	if(object == nullptr)
	{
		toRender->at(0)->setCol(r,g,b,a);
	}
}


bool Renderer::SetOpenGLAttributes()
{
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}

