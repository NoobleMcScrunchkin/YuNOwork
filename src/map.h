#pragma once
#include "game.h"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(int arr[11][20]);
    void DrawMap();

private:
    SDL_Rect src, dest;

    SDL_Texture* Ftileset;
    SDL_Texture* BG;
    SDL_Texture* Trees;

    int map[20][25];

};
