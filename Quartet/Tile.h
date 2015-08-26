#pragma once
#include <SFML\Graphics.hpp>

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 2

class Tile
{
public:
	Tile(sf::Texture& texture);
	virtual ~Tile();

	virtual void Draw(int x, int y, sf::RenderWindow* rw);

private:
	sf::Sprite baseSprite;
};

