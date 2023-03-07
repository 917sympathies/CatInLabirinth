#define SCREENWIDTH 1400
#define SCREENHEIGHT 900

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
		int result = lab.pollEvent();
		switch (result) {
		case -1:
			std::cout << "You lost :( Try next time! " << std::endl;
			isGameRunning = false;
			break;
		case 1:
			std::cout << "You've completed the game! Congragulations!!! ^_^ " << std::endl;
			isGameRunning = false;
			break;
		}
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