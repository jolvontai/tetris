#include "renderer.h"

Renderer::Renderer()
{
	this->SetOpenGLAttributes();
}

Renderer::~Renderer()
{
}
void Renderer::Render()
{

}

bool Renderer::CreateWindow()
{
	gameWindow = SDL_CreateWindow("testi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL);
	if (!gameWindow)
		return false;
	this->sdlContent = SDL_GL_CreateContext(gameWindow);
	SDL_GL_SetSwapInterval(1);
	return true;
}

bool Renderer::SetOpenGLAttributes()
{
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}

