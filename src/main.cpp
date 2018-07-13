#include "game.h"

Game *game = nullptr;

int main(int argc, char **argv)
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	romfsInit();
	game = new Game(); //Make a new instance of the Game
	game->init(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP); //Initialise the window and renderer

	while (appletMainLoop()){

		frameStart = SDL_GetTicks();

		game->handleEvents(); //Listen for inputs
		game->update(); //update objects
		game->render(); //render objects

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}

		if (!game->running()){
			break;
		}

	}

	game->clean(); //cleanup
	return 0;
}
