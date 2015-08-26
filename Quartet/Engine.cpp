#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <string>
#include "Camera.h"
#include "Level.h"

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 1

int WINDOW_W = 800, WINDOW_H = 600, CAM_SPEED = 10, TILE_SIZE = 40;
std::string WINDOW_TITLE = "Quartet v0.01";

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), WINDOW_TITLE);

	if (!window)
		return false;

	LoadImages();
	camera = new Camera(0,0,CAM_SPEED);
	currentLevel = new Level(800, 800);
	LoadLevel();

	return true;
}

void Engine::RenderFrame()
{
	//camera offsets
	int camOffsetX, camOffsetY;

	Tile* tile;

	window->clear();
	
	//Get the tile bounds we need to draw and Camera bounds
	sf::IntRect bounds = camera->GetTileBounds(TILE_SIZE);

	//Figure out how much to offset each tile
	camOffsetX = camera->GetTileOffset(TILE_SIZE).x;
	camOffsetY = camera->GetTileOffset(TILE_SIZE).y;

	//Loop through and draw each tile
	//We're keeping track of two variables in each loop. How many tiles
	//we've drawn (x and y), and which tile on the map we're drawing (tileX
	//and tileY)
	for (int y = 0, tileY = bounds.top; y < bounds.height; y++, tileY++)
	{
		for (int x = 0, tileX = bounds.left; x < bounds.width; x++, tileX++)
		{
			tile = currentLevel->GetTile(tileX, tileY);
			if (tile)
				tile->Draw((x * TILE_SIZE) - camOffsetX, (y * TILE_SIZE) - camOffsetY, window);
		}
	}

	window->display();
}

void Engine::ProcessInput()
{
	sf::Event evt;

	while (window->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
			window->close();
	}
}

void Engine::Update()
{

}

void Engine::MainLoop()
{
	while (window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go()
{
	if (!Init())
		throw "Could not initialize Engine";

	MainLoop();
}

void Engine::LoadImages()
{
	sf::Texture texture;
	if (!texture.loadFromFile("sprite1.png", sf::IntRect(10, 0, 80, 160)))
	{
		throw("Failed to load image for sprite");
	}

	textureManager.AddTexture(texture);

	if (!texture.loadFromFile("sprite2.png", sf::IntRect(10, 0, 80, 160)))
	{
		throw("Failed to load image for sprite");
	}

	textureManager.AddTexture(texture);
}

//Temp
void Engine::LoadLevel()
{
	//Temporary level for testing
	currentLevel = new Level(40, 40);

	Tile* tile;
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (y % 4 == 0)
				tile = new Tile(textureManager.GetTexture(1));
			else
				tile = new Tile(textureManager.GetTexture(0));

			currentLevel->AddTile(x, y, tile);
		}
	}
}