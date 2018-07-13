#ifndef game_hpp
#define game_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <switch.h>
#include <string.h>
#include <stdio.h>

class Game {
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer *renderer;

private:
    SDL_Window *window;
    bool isRunning;
};

#endif
