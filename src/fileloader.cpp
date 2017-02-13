#include "fileloader.h"

FileLoader::FileLoader()
{
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !( IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "ENGINE::LOADER::INIT::IMAGE " << SDL_GetError() << std::endl;
    }
}
GLuint FileLoader::GetTexture(std::string texName)
{
    if(this->textures.find(texName) != this->textures.end() || this->LoadImg(texName))
    {
        return this->textures[texName];
    }
    return 0;
}
bool FileLoader::LoadImg(std::string texName)
{
	GLuint textureID = 0;
    SDL_Surface* surface = IMG_Load(texName.c_str());

	if (surface == NULL)
		return false;
		
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	int mode = GL_RGB;

	if (surface->format->BytesPerPixel == 4) {
		mode = GL_RGBA;
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h,
		0, mode, GL_UNSIGNED_BYTE, surface->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


	this->textures[texName] = textureID;
    return true;
}