#pragma once


#include <string>
#include <iostream>
#include <vector>
#include "element2d.h"
#include "game.h"

class Game
{
public:
	Game();
	~Game();

	std::vector<Element2D*>* Init();
	void HandleInput();
	void Update();
	void Render();
	void Start();
	void CheckSDLError(int line);

private:
	std::vector<Element2D*> gameObjects;
	

};
