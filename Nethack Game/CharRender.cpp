#include "CharRender.h"

#include <iostream>

Asterisk::Asterisk(SDL_Renderer* renderer)
{
	Texture* floor_texture = new Texture(renderer, "floor");
	gRenderer = renderer;
	this->surface = floor_texture->getSurface();
	this->texture = floor_texture->getTexture();
}

Asterisk::~Asterisk()
{
}

void Asterisk::render()
{
	
	
	SDL_Rect floor_destination = { tileArr[i][j]->getTileWidthDistance(), tileArr[i][j]->getTileHeightDistance(), surface->w, surface->h };

	if (SDL_RenderCopy(gRenderer, tileArr[i][j]->getTexture(), NULL, &floor_destination) < 0)
		std::cout << SDL_GetError();
}

//--------------------------------------------------------------------------

PlayerChar::PlayerChar(SDL_Renderer* renderer)
{
	Texture* player_texture = new Texture(renderer, "player");
	gRenderer = renderer;
	this->surface = player_texture->getSurface();
	this->texture = player_texture->getTexture();
}

void PlayerChar::render()
{
	
}
