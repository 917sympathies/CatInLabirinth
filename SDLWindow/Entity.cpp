#include "Entity.h"

Entity::Entity(Vector2f _pos, SDL_Texture* p_texture) 
	: pos(_pos), texture(p_texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32*2;
	currentFrame.h = 32*2;
}

Vector2f& Entity::getPos() {
	return pos;
}

SDL_Texture* Entity::getTexture()
{
	return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}