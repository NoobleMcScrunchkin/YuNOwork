#include "map.h"
#include "textureman.h"

int lvl1[11][20] = {
    {91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map(){
    Ftileset = TextureManager::LoadTexture("romfs:/Tileset.png");
    BG = TextureManager::LoadTexture("romfs:/Background.png");
    Trees = TextureManager::LoadTexture("romfs:/Trees.png");

    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = src.h = 16;
    dest.w = dest.h = 64;
    dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[11][20]){
    for (int row = 0; row < 11; row++){
        for (int col = 0; col < 20; col++){
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap(){
    int type = 0;

    for (int row = 0; row < 11; row++){
        for (int col = 0; col < 20; col++){
            type = map[row][col];

            dest.x = col * 64;
            dest.y = (row * 64) + 8;

            switch (type){
                case 91:
                    src.x = src.y = 0;
                    src.w = 512;
                    src.h = 320;
                    dest.w = 1280;
                    dest.h = 704;
                    TextureManager::Draw(BG, src, dest);
                    break;
                case 1:
                    src.w = src.h = 16;
                    dest.w = dest.h = 64;
                    src.x = 48;
                    src.y = 0;
                    TextureManager::Draw(Ftileset, src, dest);
                    break;
                case 2:
                    src.w = src.h = 16;
                    dest.w = dest.h = 64;
                    src.x = 48;
                    src.y = 16;
                    TextureManager::Draw(Ftileset, src, dest);
                    break;
                case 3:
                    src.w = src.h = 16;
                    dest.w = dest.h = 64;
                    src.x = 48;
                    src.y = 32;
                    TextureManager::Draw(Ftileset, src, dest);
                    break;
                case 4:
                    src.w = 256;
                    src.h = 128;
                    dest.w = 1024;
                    dest.h = 512;
                    src.x = 0;
                    src.y = 0;
                    dest.y = dest.y - 448;
                    TextureManager::Draw(Trees, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
