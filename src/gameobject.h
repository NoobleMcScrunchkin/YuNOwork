#pragma once
#include "game.h"

class GameObject {
public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();
    void Update();
    void Render();
    bool Movement();
    u32 kDownAbb;
    u32 kUpAbb;

private:
    int xpos;
    int ypos;
    int xacc = 0;
    int yacc = 5;
    int xvel = 0;
    int yvel = 0;
    int movement = 0;
    bool moved = 0;
    bool jumped = 0;
    int timer = 0;
    int jtimer = 0;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};
