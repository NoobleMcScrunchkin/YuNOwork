#include "game.h"
#include "textureman.h"
#include "gameobject.h"
#include "map.h"
#include <string.h>
#include <stdio.h>
GameObject* player;
Map* map;
SDL_Renderer* Game::renderer = nullptr;

Game::Game(){

}
Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool flags){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        printf("Failed to initialise SDL\n");
        isRunning = false;
    } else {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window == 0){
            printf("Failed to make window\n");
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        if (renderer == 0){
            printf("Failed to make renderer\n");
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
        isRunning = true;
    }

    map = new Map();
    player = new GameObject("romfs:/player.png", 0, 0);

}

void Game::handleEvents(){
    isRunning = player->Movement();
}

void Game::update(){
    player->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyRenderer(renderer);
  	SDL_DestroyWindow(window);
  	SDL_Quit();
}
