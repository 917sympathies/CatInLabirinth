#define SCREENWIDTH 1400
#define SCREENHEIGHT 900
#define STARTGAMEMSG "Take the cat to the door without touching walls"

#include <iostream>
#include <vector>
#include <conio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "RendererWindow.h"
#include "Entity.h"
#include "Text.h"
#include "Labirinth.h"

int main(int argc, char* argv[]) 
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "INIT ERROR" << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_init has failed" << std::endl;

	if (TTF_Init() < 0)
		std::cout << "TTF_Init has failed" << std::endl;

	RendererWindow window("LabirinthMeow", SCREENWIDTH, SCREENHEIGHT);
	std::string gameStatus = STARTGAMEMSG;
	Text text(window.getRenderer(), "res/arial.ttf", 50, gameStatus, { 255, 255, 255, 255 });

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
			//gameStatus = "You lost :( Try next time!";
			//Text newText1(window.getRenderer(), "res/arial.ttf", 50, "You lost :( Try next time!", { 255, 255, 255, 255 });
			text = Text::Text(window.getRenderer(), "res/arial.ttf", 50, "You lost :( Try next time!", { 255, 255, 255, 255 });
			//isGameRunning = false;
			break;
		case 1:
			//gameStatus = "You've completed the game! Congragulations!!! ^_^";
			//Text newText2(window.getRenderer(), "res/arial.ttf", 50, "You've completed the game! Congragulations!!! ^_^", { 255, 255, 255, 255 });
			text = Text::Text(window.getRenderer(), "res/arial.ttf", 50, "You've completed the game! Congragulations!!! ^_^", { 255, 255, 255, 255 });
			//isGameRunning = false;
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
		text.display((SCREENWIDTH / 2) - (gameStatus.size() * 10), 20, window.getRenderer());
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}