#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 3

class Camera final
{
public:
	Camera(int w, int h, float speed);
	~Camera();

	//Move camera immediately to coordinates
	void Move(int x, int y);
	void MoveCenter(int x, int y);

	//Sets camera target
	void GoTo(int x, int y);
	void GoToCenter(int x, int y);

	//Updates camera position
	void Update();

	sf::Vector2i GetPosition() const { 
		return sf::Vector2i(static_cast<int>(position.x), static_cast<int>(position.y)); }
	//Helper function to retrieve camera offset from nearest tile
	sf::Vector2i GetTileOffset(int tileSize) const { 
		return sf::Vector2i(static_cast<int>(position.x) % tileSize, static_cast<int>(position.y) % tileSize); }
	//Helper function for retreiving a rectangle defining which tiles are visible through camera
	sf::IntRect GetTileBounds(int tileSize);

private:
	//Absolute position of camera
	sf::Vector2f position;
	//Target position of camera
	sf::Vector2f target;
	//Size of camera
	sf::Vector2i size;
	//Speed of camera, value between 0.0 and 1.0
	float speed;
};

