#include "RendererWindow.h"

RendererWindow::RendererWindow(const char* w_title, int w_w, int w_h)
	:window(NULL)
{
	window = SDL_CreateWindow(w_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_w, w_h, SDL_WINDOW_SHOWN);
	if (window == NULL)
		std::cout << "WINDOW FAILED TO INIT" << std::endl;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RendererWindow::loadTexture(const char* p_filePath) 
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);
	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	return texture;
}

void RendererWindow::render(Entity& p_entity) 
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;
	SDL_Rect dst;
	dst.x = p_entity.getPos().x;
	dst.y = p_entity.getPos().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;
	SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

SDL_Renderer* RendererWindow::getRenderer() {
	return renderer;
}

void RendererWindow::display() 
{
	SDL_RenderPresent(renderer);
}

void RendererWindow::clear() 
{
	SDL_RenderClear(renderer);
}

void RendererWindow::cleanUp() 
{
	SDL_DestroyWindow(window);
}