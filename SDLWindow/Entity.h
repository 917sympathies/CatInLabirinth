#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Math.h"

class Entity
{
public:
	Vector2f& getPos();
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
	Entity(Vector2f _pos, SDL_Texture* p_texture);
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

