#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Entity
{
public:
	float getX();
	float getY();
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
	Entity(float p_x, float p_y, SDL_Texture* p_texture);
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};

