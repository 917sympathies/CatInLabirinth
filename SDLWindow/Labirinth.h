#pragma once

#define LABIRINTHSIZE 10
#define STARTPOS 100

#include <iostream>
#include <vector>

#include "Entity.h"
#include "Math.h"

class Labirinth
{
public:
	Labirinth();
	std::vector<Entity> parseLabirinth(SDL_Texture *textureWall, SDL_Texture *texturePlayer, SDL_Texture* textureEnd);
	int pollEvent();
private:
	std::string* labirinth;
};

