#pragma once

#include "Tile.h"
#include "Texture.h"
#include "Player.h"
#include "Tile.h"
#include "Wall.h"
#include "CharRender.h"
#include <string>

class Room {
	private:
		int layout_index;
		std::string room_name;

		SDL_Renderer* gRenderer;

		Tile* tileArr[23][35];

		
		
			/*char facing;
			int lengthOfLoop;
			int xCoord;
			int yCoord;*/
		

		Tile::tile_struct* tile_obj_struct;

	public:
		Room(int, SDL_Renderer*, Tile::tile_struct*);

		Tile* getTileArr();

		bool replaceTileArrayWithRoomData();
		void setTileArr(); //for when I need to replace floor tiles with player tiles

		void resetTilesToFloor();
		void replaceWithPlayerTile(Tile* tileArr[23][35], Texture*, Player*);
		void drawTileTexturesToScreen(Tile* tileArr[23][35], SDL_Renderer*);
};