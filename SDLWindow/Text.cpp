#include "Text.h"


Text::Text(SDL_Renderer *renderer,
	const std::string& font_path, 
	int font_size, 
	const std::string& message_text, 
	const SDL_Color& color) 
{
	text_texture = loadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(text_texture, NULL, NULL, &textRect.w, &textRect.h);
}

void Text::display(int x, int y, SDL_Renderer *renderer) const 
{
	textRect.x = x;
	textRect.y = y;
	SDL_RenderCopy(renderer, text_texture, NULL, &textRect);
}

SDL_Texture* Text::loadFont(SDL_Renderer* renderer,
	const std::string& font_path, 
	int font_size, 
	const std::string& message_text, 
	const SDL_Color& color) 
{
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
		std::cout << "Failed to load a font!! "<< TTF_GetError() << std::endl;
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface)
		std::cout << "Failed to create text surface!! " << TTF_GetError() << std::endl;
	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture)
		std::cout << "Failed to create text texture!! " << TTF_GetError() << std::endl;
	SDL_FreeSurface(text_surface);
	return text_texture;
}