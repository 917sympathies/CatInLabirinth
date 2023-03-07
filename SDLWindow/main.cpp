#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

#include <iostream>
#include <vector>
#include <conio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "RendererWindow.h"
#include "Entity.h"
#include "Labirinth.h"

int main(int argc, char* argv[]) 
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "INIT ERROR" << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_init has failed" << std::endl;

	RendererWindow window("LabirinthMeow", SCREENWIDTH, SCREENHEIGHT);

	SDL_Texture* groundTexture = window.loadTexture("img/ground.jpg");
	SDL_Texture* playerTexture = window.loadTexture("img/cat.png");
	SDL_Texture* doorTexture = window.loadTexture("img/door.png");

	Labirinth lab;

	std::vector<Entity> labirinthWalls = lab.parseLabirinth(groundTexture, playerTexture, doorTexture);

	bool isGameRunning = true;

	SDL_Event event;

	while (isGameRunning) {
		lab.pollEvent();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				isGameRunning = false;
		}
		labirinthWalls = lab.parseLabirinth(groundTexture, playerTexture, doorTexture);
		window.clear();
		for (auto ent : labirinthWalls) {
			window.render(ent);
		}
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}