#pragma once

#include "Tile.h"

class VertWall : public Tile 
{
	private:
		
	public:
		VertWall(SDL_Renderer*);
		~VertWall();

		void render();
};

//--------------------------------------------------------------------------

class HorizontalWall : public Tile
{
private:

public:
	HorizontalWall(SDL_Renderer*);
	~HorizontalWall();

	void render();
};

//--------------------------------------------------------------------------

class RightUpCorner : public Tile
{
private:
	
public:
	RightUpCorner(SDL_Renderer*);
	~RightUpCorner();

	void render();
};

//--------------------------------------------------------------------------

class RightDownCorner : public Tile
{
private:
	
public:
	RightDownCorner(SDL_Renderer*);
	~RightDownCorner();

	void render();
};

//--------------------------------------------------------------------------

class LeftUpCorner : public Tile
{
private:
	
public:
	LeftUpCorner(SDL_Renderer*);
	~LeftUpCorner();

	void render();
};

//--------------------------------------------------------------------------

class LeftDownCorner : public Tile
{
private:
	
public:
	LeftDownCorner(SDL_Renderer*);
	~LeftDownCorner();

	void render();
};