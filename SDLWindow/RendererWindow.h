#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Entity.h"

class RendererWindow
{
public:
	RendererWindow(const char* w_title, int w_w, int w_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	SDL_Renderer* getRenderer();
	void clear();
	void display();
	void render(Entity& p_entity);
	void cleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

