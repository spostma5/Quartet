#include "Level.h"
#include <vector>
#include "Tile.h"

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 3

Level::Level(int w, int h)
{
	SetDimension(w, h);
	this->w = w;
	this->h = h;
}

Level::~Level()
{
}

void Level::SetDimension(int w, int h)
{
	map.resize(w);

	//Each row has h columns of null Tile pointers
	for (int i = 0; i < w; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, Tile* tile)
{
	map[x][y] = tile;
}

Tile* Level::GetTile(int x, int y) const
{
	return map[x][y];
}

void Level::LoadLevel()
{
	//TODO
}