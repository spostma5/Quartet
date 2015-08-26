#include "Tile.h"
#include <SFML\Graphics.hpp>

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 2

Tile::Tile(sf::Texture& texture)
{
	baseSprite.setTexture(texture,true);
}

Tile::~Tile()
{
}

void Tile::Draw(int x, int y, sf::RenderWindow* rw)
{
	baseSprite.setPosition(x, y);
	rw->draw(baseSprite);
}