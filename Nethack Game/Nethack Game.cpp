/*
To-Do List:
add an info section on the top
- add health bar/info
- currently equipped items
- current level/area
- text message section

make a room class and start building rooms

bombs
walls block sight
cracked walls
item that increases sight range
add enemies
add attacks
add magic
add arrows
make a door
make it so you can only see enemies within a certain range
add item menu/screen
make a treasure chest
*/

#include "Player.h"
#include "Texture.h"
#include "Tile.h"
#include "Room.h"
#include "Wall.h"
#include "CharRender.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>
#include <array>

bool drawStatusSection(Tile* tileArr[23][35], SDL_Renderer* renderer) {
    const int SCREEN_WIDTH = 828;
    int x1 = tileArr[0][0]->getStartingTileWidthDistance();
    int x2 = x1 + SCREEN_WIDTH;
    int y1 = -4 + tileArr[0][0]->getStartingTileHeightDistance();
    int y2 = y1 - 1;
    
    SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
    SDL_RenderDrawLine(renderer, x1, y2, x2, y2);
    SDL_RenderPresent(renderer);
    return true;
}

bool drawBoard(Player* player, Texture* floor_texture, Texture* player_texture, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, Tile* tileArr[23][35], Room* room) {
    
    //resets rendering target
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    //makes a black screen
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 00, 00, 00));
    SDL_UpdateWindowSurface(window);

    room->replaceTileArrayWithRoomData();

    //resets all floor tiles to the floor tile
    //room->resetTilesToFloor(tileArr, floor_texture);

    

    

    //replace a floor tile with player tile   
    //room->replaceWithPlayerTile(tileArr, player_texture, player);

    //draws tile textures onto screen
    room->drawTileTexturesToScreen(tileArr, renderer);

    return true;
}

int gameLoop(Player* player, SDL_Surface* screenSurface, SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    bool quit = false;

    SDL_Event e;

    //create a tile struct with all of the child objects of tile class
    Tile::tile_struct* tile_obj_struct = Tile::createTileStruct(renderer, floor_texture, player_texture);

    //create a new object with the starting room id
    Room* room = new Room(1, renderer, tile_obj_struct);

    
    

    //creates a 2D tile array and assigns the objects to the floor texture, gives them the floor name, and gives them proper pixel coordinates and x/y coordinates
    //Tile* tileArr[23][35];
    //must first create objects to be able to pull out starting tile width distance. This way I can control that value from the class, not search for the variable in the main function
    

    

    //creates child objects of the Tile class from Wall.h
    

   /* vert_wall.setXCoord(13);
    vert_wall.setYCoord(13);
    tileArr[13][13] = &vert_wall;*/
    

    drawBoard(player, screenSurface, window, renderer, texture, tileArr, room);
    drawStatusSection(tileArr, renderer);

    while (!quit) {

        
        //keyboard event handling
        while (SDL_WaitEvent(&e) != 0) {
            //if the user does an action that triggers the SDL_QUIT
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    
                    case SDLK_UP:
                        if (player->getYCoord() != 0)
                            player->subYCoord(tileArr);
                        break;

                    case SDLK_DOWN:
                        if (player->getYCoord() != 22)
                            player->addYCoord(tileArr);
                        break;

                    case SDLK_LEFT:
                        if (player->getXCoord() != 0)
                            player->subXCoord(tileArr);
                        break;

                    case SDLK_RIGHT:
                        if (player->getXCoord() != 34)
                            player->addXCoord(tileArr);
                        break;

                }
                drawBoard(player, floor_texture, player_texture, screenSurface, window, renderer, texture, tileArr, room);
                drawStatusSection(tileArr, renderer);
            }
        }
    }
    return 0;
}

bool sdlAssignWindowSurfaceRendererTexture(SDL_Window*& window, SDL_Surface*& screenSurface, SDL_Renderer*& renderer, SDL_Texture*& texture) {
    const int SCREEN_WIDTH = 828;
    const int SCREEN_HEIGHT = 606; //orig height was 570
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL video init error. SDL Error : " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() < 0) {
        std::cout << "SDL2_TTF failed to initialize. TTF Error: " << TTF_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Nethack Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    screenSurface = SDL_GetWindowSurface(window);
    if (screenSurface == NULL) {
        std::cout << "Screen surface could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (texture == NULL) {
        std::cout << "Texture could not be created. SDL Error: " << SDL_GetError() << std::endl;
    }

    return true;
}

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;

    Player* player = NULL;
    Texture* player_texture = NULL;
    Texture* floor_texture = NULL;

    sdlAssignWindowSurfaceRendererTexture(window, screenSurface, renderer, texture);

    player = new Player();
    

    gameLoop(player, screenSurface, window, renderer, texture);

    SDL_StopTextInput();
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    screenSurface = NULL;
    renderer = NULL;
    texture = NULL;
    player = NULL;
    player_texture = NULL;
    floor_texture = NULL;
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}