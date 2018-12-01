#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

#include "Hitbox.h"
#include "LoadModel.h"

#define FLAT_TILE 0
#define WALL_TILE 1

#define TILE_SIZE 100 // decimeters
#define FLOOR_TILE_ALPHA .7

class Tile {
private:
	int map_x, map_y, map_z; // Tile location
	int type;
	unsigned int texture;
	Hitbox *hitbox;

public:
	Tile();
	Tile( int tileType, int mx, int my, int mz, unsigned int t );
	~Tile();

	bool testTileHit( Hitbox *other );

	void display();
};

#endif