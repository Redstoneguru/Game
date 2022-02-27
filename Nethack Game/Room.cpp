#include "Room.h"
#include "Texture.h"
#include "Tile.h"
#include <iostream>



Room::Room(int x, SDL_Renderer* renderer, Tile::tile_struct* tile_struct)
{
    layout_index = x;
    gRenderer = renderer;
    tile_obj_struct = tile_struct;
    replaceTileArrayWithRoomData();
}


Tile* Room::getTileArr()
{
    //return tileArr;
}

bool Room::replaceTileArrayWithRoomData()
{
    for (int i = 0; i < 23; i++)
        for (int j = 0; j < 35; j++) {
            tileArr[i][j] = new Asterisk(gRenderer);
        }

    int tileWidthDistance = tileArr[0][0]->getStartingTileWidthDistance();
    int tileHeightDistance = tileArr[0][0]->getStartingTileHeightDistance();

    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < 35; j++) {
            tileArr[i][j]->setTileWidthDistance(tileWidthDistance);
            tileArr[i][j]->setTileHeightDistance(tileHeightDistance);
            tileArr[i][j]->setXCoord(j);
            tileArr[i][j]->setYCoord(i);
            tileWidthDistance += 24;
        }
        tileHeightDistance += 24;
        tileWidthDistance = tileArr[0][0]->getStartingTileWidthDistance();
    }
   //switch (layout_index)
   // {
       // case 1:





    //    case 1:
    //        room_name = "starting room";
    //        //draws upper left corner
    //        for (int i = 0; i < 8; i++) 
    //        {
    //            tileArr[i][8]->setName("vertical wall");
    //            tileArr[8][i]->setName("horizontal wall");
    //        }
    //        tileArr[8][8]->setName("right down corner");
    //        
    //        //draws bottom left corner
    //        for (int i = 0; i < 8; i++)
    //        {
    //            tileArr[14][i]->setName("horizontal wall");
    //            tileArr[22 - i][8]->setName("vertical wall");
    //        }
    //        tileArr[14][8]->setName("right up corner");
    //        
    //        tileArr[13][13]->draw();
    //        break;
    //    case 2:

    //    case 3:

    //    default:
    //        std::cout << "invalid room id" << std::endl;
    //}
	return true;
}

void Room::resetTilesToFloor()
{
    //resets all tiles to the floor tile
    for (int i = 0; i < 23; i++) 
        for (int j = 0; j < 35; j++) {
            tileArr[i][j] = tile_obj_struct->floor_tile;
            
        }
}

void Room::replaceWithPlayerTile(Tile* tileArr[23][35], Texture* player_texture, Player* player)
{
    //replace a floor tile with player tile
    //tileArr[player->getYCoord()][player->getXCoord()]->setName("player");
    tileArr[player->getYCoord()][player->getXCoord()]->setTexture(player_texture->getTexture());
    tileArr[player->getYCoord()][player->getXCoord()]->setSurface(player_texture->getSurface());
}

void Room::drawTileTexturesToScreen(Tile* tileArr[23][35], SDL_Renderer* renderer)
{
    //draws tile textures onto screen
    for (int i = 0; i < 23; i++)
        for (int j = 0; j < 35; j++)
        {
            if (tileArr[i][j]->getName() == "floor")
            {
                SDL_Rect floor_destination = { tileArr[i][j]->getTileWidthDistance(), tileArr[i][j]->getTileHeightDistance(), tileArr[i][j]->getSurface()->w, tileArr[i][j]->getSurface()->h };

                if (SDL_RenderCopy(renderer, tileArr[i][j]->getTexture(), NULL, &floor_destination) < 0)
                    std::cout << SDL_GetError();
            }
            else if (tileArr[i][j]->getName() == "player")
            {
                //adds plus one to account for the fact that the & was a pixel off to the left
                SDL_Rect player_destination = { tileArr[i][j]->getTileWidthDistance() + 1, tileArr[i][j]->getTileHeightDistance(), tileArr[i][j]->getSurface()->w, tileArr[i][j]->getSurface()->h };

                if (SDL_RenderCopy(renderer, tileArr[i][j]->getTexture(), NULL, &player_destination) < 0)
                    std::cout << SDL_GetError();
            }
            else {
                for (int i = 0; i < 23; i++)
                    for (int j = 0; j < 35; j++){
                        tileArr[i][j]->draw();
                }
            }
        }
    

 

    SDL_RenderPresent(renderer);
}
