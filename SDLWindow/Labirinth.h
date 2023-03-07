#pragma once

#define LABIRINTHSIZE 10

#include <iostream>
#include <vector>

#include "Entity.h"

class Labirinth
{
public:
	Labirinth();
	std::vector<Entity> parseLabirinth(SDL_Texture *textureWall, SDL_Texture *texturePlayer, SDL_Texture* textureEnd);
	void pollEvent();
	void changePlayerPosition(SDL_Keycode keycode);
private:
	std::string* labirinth;
};

