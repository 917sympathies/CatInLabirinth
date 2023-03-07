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

int Labirinth::pollEvent() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			try {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT: // LEFT
					for (int i = 0; i < LABIRINTHSIZE; i++)
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i][j - 1] == ' ')
									std::swap(labirinth[i][j], labirinth[i][j - 1]);
								else if (labirinth[i][j - 1] == '&') return 1;
								else return -1;
							}
						}
					break;
				case SDLK_UP: // UP
					for (int i = 0; i < LABIRINTHSIZE; i++)
						for (int j = 0; j < labirinth[i].size(); j++) {
							if (labirinth[i][j] == '$') {
								if (labirinth[i - 1][j] == ' ')
									std::swap(labirinth[i][j], labirinth[i - 1][j]);
								else if (labirinth[i - 1][j] == '&') return 1;
								else return -1;
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
								else if (labirinth[i][j + 1] == '&') return 1;
								else return -1;
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
								else if (labirinth[i + 1][j] == '&') return 1;
								else return -1;
							}
						}
						if (!ok) break;
					}
					break;
				}
			}
			catch (const char* exc) {
				return -1;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			std::cout << event.motion.x << ", " << event.motion.y << std::endl;
		}
	}
	return 0;
}

std::vector<Entity> Labirinth::parseLabirinth(SDL_Texture* textureWall, SDL_Texture* texturePlayer, SDL_Texture* textureEnd) {
	std::vector<Entity> lab;
	for (int i = 0; i < LABIRINTHSIZE; i++) {
		for (int j = 0; j < labirinth[i].size(); j++) {
			if (labirinth[i][j] == '*')
				lab.push_back(Entity(Vector2f(j * 64 + STARTPOS, i * 64 + STARTPOS), textureWall));
			if (labirinth[i][j] == '$')
				lab.push_back(Entity(Vector2f(j * 64 + STARTPOS, i * 64 + STARTPOS), texturePlayer));
			if (labirinth[i][j] == '&')
				lab.push_back(Entity(Vector2f(j * 64 + STARTPOS, i * 64 + STARTPOS), textureEnd));
		}
	}
	return lab;
}