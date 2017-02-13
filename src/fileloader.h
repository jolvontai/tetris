#pragma once

#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<GL/glew.h>
#include<string>
#include<iostream>
#include<map>

class FileLoader
{
public:
    FileLoader();
    GLuint GetTexture(std::string texName);
private:
    bool LoadImg(std::string texName);
    std::map<std::string,GLuint> textures;
};