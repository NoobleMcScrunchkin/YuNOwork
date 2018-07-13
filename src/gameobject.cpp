#include "game.h"
#include "textureman.h"
#include "gameobject.h"
#include "map.h"

GameObject::GameObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::Update(){
    srcRect.h = 128;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

}

void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

bool GameObject::Movement(){
    yacc = 5;
    hidScanInput(); //Check Inputs
    u32 kDownAbb = hidKeysDown(CONTROLLER_P1_AUTO); //Check for buttons pressed down by player 1
    u32 kUpAbb = hidKeysUp(CONTROLLER_P1_AUTO);

    if (kDownAbb & KEY_PLUS){ //Check if plus has been pressed
        return false;
    }

    if (kDownAbb & KEY_RIGHT){
        xacc = 1;
    } else if (kDownAbb & KEY_LEFT){
        xacc = -1;
    }
    if (kDownAbb & KEY_A && jumped == 0){
      yacc = -40;
      yvel = 0;
      jumped = 1;
    }

    if (kUpAbb & KEY_RIGHT){
        xacc = 0;
    } else if (kUpAbb & KEY_LEFT){
        xacc = 0;
    }

    if (xvel < 1 && xvel > -1){
        xvel = 0;
    }

    if (xacc == 0){
      xvel = xvel * 0.5;
    }

    if (xpos > 1216){
      xpos = 1216;
      xvel = 0;
    }
    if (xpos < 0){
      xpos = 0;
      xvel = 0;
    }
    if (ypos > 520){
      yvel = 0;
    }

    xvel = xvel + xacc;
    xpos = xpos + (xvel + 0.5 * xacc);
    yvel = yvel + yacc;
    ypos = ypos + yvel + 0.5 * yacc;

    if (ypos > 520){
      ypos = 520;
      jumped = 0;
    }

    return true;
}
