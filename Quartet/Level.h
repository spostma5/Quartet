#pragma once
#include <vector>
#include "Tile.h"

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 3

class Level
{
public:
	Level(int w, int h);
	virtual ~Level();

	virtual void AddTile(int x, int y, Tile* tile);
	virtual Tile* GetTile(int x, int y) const;
	virtual void LoadLevel();

	virtual int GetWidth() const { return w; };
	virtual int GetHeight() const { return h; };

private:
	std::vector<std::vector<Tile*>> map;
	int w, h;

	virtual void SetDimension(int w, int h);
};

