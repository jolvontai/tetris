#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "element2d.h"
#include"interface.h"

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
	void SetEngine(Engine& engine);

private:
	std::vector<Element2D*> gameObjects;
	

};
