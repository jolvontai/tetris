#include "renderer.h"
#include<iostream>

Renderer::Renderer()
{
	//std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	SetOpenGLAttributes();
	
	vertexShaderSource = "#version 300 es \n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";
	fragmentShaderSource = "#version 300 es \n"
		"precision highp float;\n"
		"out vec4 color;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"color = ourColor;\n"
		"}\n\0";
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
	GLint success;
	GLchar infoLog[512];


	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX:COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT:COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM:LINK_FAILED\n" << infoLog << std::endl;
		return false;
	}
	glUseProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);


	
	return true;
	
}

Renderer::~Renderer()
{
	glDeleteProgram(shaderProgram);
	toRender = nullptr;
	delete toRender;
	SDL_GL_DeleteContext(sdlContent);
	SDL_DestroyWindow(gameWindow);
	SDL_Quit();

}
void Renderer::Render()
{
	glUseProgram(shaderProgram);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < toRender->size();i++)
	{
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
void Renderer:SetObjCol(Element2D* object, GLfloat r = 0,GLfloat g = 0,GLfloat b = 0,GLfloat a = 0)
{
	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	glUseProgram(shaderProgram);
	glUniform4f(vertexColorLocation, r,g,b,a);
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

