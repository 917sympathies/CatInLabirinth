#include "Labirinth.h"

Labirinth::Labirinth() {
	labirinth = new std::string[LABIRINTHSIZE]{
			"**$****************",
			"** **    **********",
			"** ** ** **    ****",
			"** ** ** ** ** ****",
			"** ** ** ** ** ****",
			"** ** ** ** ** ****",
			"** ** ** ** ** ****",
			"** ** **    ** ****",
			"**    ******** ****",
			"**************&****"
	};
}

void Labirinth::pollEvent() {
	SDL_Event event;
	if(SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			try {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT: // LEFT
					for (int i = 0; i < LABIRINTHSIZE; i++)
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i][j - 1] == ' ')
									std::swap(labirinth[i][j], labirinth[i][j - 1]);
							}
						}
					break;
				case SDLK_UP: // UP
					for (int i = 0; i < LABIRINTHSIZE; i++)
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i - 1][j] == ' ')
									std::swap(labirinth[i][j], labirinth[i - 1][j]);
							}
						}
					break;
				case SDLK_RIGHT: // RIGHT
					for (int i = 0; i < LABIRINTHSIZE; i++)
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i][j + 1] == ' ') {
									std::swap(labirinth[i][j], labirinth[i][j + 1]);
									break;
								}
							}
						}
					break;
				case SDLK_DOWN: // DOWN
					bool ok = true;
					for (int i = 0; i < LABIRINTHSIZE; i++) {
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i + 1][j] == ' ') {
									std::swap(labirinth[i][j], labirinth[i + 1][j]);
									ok = false;
									break;
								}
							}
						}
						if (!ok) break;
					}
					break;
				}
			}
			catch (const char* exc) {

			}
		}
	}
}

void Labirinth::changePlayerPosition(SDL_Keycode keycode) {
	try {

	}
	catch (const char* exc) {

	}
}

std::vector<Entity> Labirinth::parseLabirinth(SDL_Texture* textureWall, SDL_Texture* texturePlayer, SDL_Texture* textureEnd) {
	std::vector<Entity> lab;
	for (int i = 0; i < LABIRINTHSIZE; i++) {
		for (int j = 0; j < labirinth[i].size(); j++) {
			if (labirinth[i][j] == '*')
				lab.push_back(Entity(j * 64, i * 64, textureWall));
			if (labirinth[i][j] == '$')
				lab.push_back(Entity(j * 64, i * 64, texturePlayer));
			if (labirinth[i][j] == '&')
				lab.push_back(Entity(j * 64, i * 64, textureEnd));
		}
	}
	return lab;
}