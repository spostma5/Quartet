#pragma once
#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"
#include "Camera.h"
#include "Level.h"

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 1

class Engine final
{
public:
	Engine();
	~Engine();

	//Start engine
	void Go();

private:
	sf::RenderWindow* window;
	TextureManager textureManager;
	Camera* camera;
	Level* currentLevel;

	//Temp
	void LoadLevel();

	//Initialize engine
	bool Init();
	//Main game loop
	void MainLoop();
	//Render a single frame
	void RenderFrame();
	//Process user input
	void ProcessInput();
	//Updates engine internals
	void Update();
	//Load images for texture
	void LoadImages();
};

