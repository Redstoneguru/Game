#pragma once

#include "Tile.h"

class Asterisk : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;

	public:
		Asterisk(SDL_Renderer*);
		~Asterisk();

		void render();
};

//--------------------------------------------------------------------------

class PlayerChar : public Tile {
	private:
		SDL_Renderer* gRenderer;
		SDL_Surface* surface;
		SDL_Texture* texture;

	public:
		PlayerChar(SDL_Renderer*);

		void render();
};