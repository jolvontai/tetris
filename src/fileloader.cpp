#include "fileloader.h"

FileLoader::FileLoader()
{
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !( IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "ENGINE::LOADER::INIT::IMAGE " << SDL_GetError() << std::endl;
    }
}
GLuint* FileLoader::GetTexture(std::string texName)
{
    if(this->textures.find(texName) != this->textures.end())
    {
        return this->textures[texName];
    }
    else
    {
        GLuint* texID = this->LoadImg(texName);
        this->textures[texName] = texID;
        return this->textures[texName];

    }
    return NULL;
}
GLuint* FileLoader::LoadImg(std::string texName)
{
    GLuint* textureID = new GLuint();

    SDL_Surface* surface = IMG_Load(texName.c_str());

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);

    int mode = GL_RGB;

    if(surface->format->BytesPerPixel == 4) {
        mode = GL_RGBA;
    }

    glTexImage2D(GL_TEXTURE_2D, 0,mode,surface->w,surface->h,
    0,mode,GL_UNSIGNED_BYTE, surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}