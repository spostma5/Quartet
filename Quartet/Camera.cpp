#include "Camera.h"
#include <SFML\Graphics.hpp>
#include <math.h>

//Taken from http://www.dreamincode.net/forums/topic/230524-c-tile-engine-from-scratch-part-1/
//RevTorA's C++ Tile Engine From Scratch Tutorial - Part 3

int MOVE_SPEED = 60;

Camera::Camera(int w, int h, float speed)
{
	size.x = w;
	size.y = h;

	if (speed < 0.0)
		speed = 0.0;
	if (speed > 1.0)
		speed = 1.0;

	this->speed = speed;
}

Camera::~Camera()
{
}

void Camera::Move(int x, int y)
{
	position.x = static_cast<float>(x);
	position.y = static_cast<float>(y);
	target.x = static_cast<float>(x);
	target.y = static_cast<float>(y);
}

void Camera::MoveCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	position.x = static_cast<float>(x);
	position.y = static_cast<float>(y);
	target.x = static_cast<float>(x);
	target.y = static_cast<float>(y);
}

void Camera::GoTo(int x, int y)
{
	target.x = static_cast<float>(x);
	target.y = static_cast<float>(y);
}

void Camera::GoToCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	target.x = static_cast<float>(x);
	target.y = static_cast<float>(y);
}

void Camera::Update()
{
	//x distance, y distance, and Euclidean distance
	float x, y, d;
	//Velocity magnitudes
	float vx, vy, v;

	x = static_cast<float>(target.x - position.x);
	y = static_cast<float>(target.y - position.y);

	if ((x*x + y*y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;
	}
	else
	{
		//Distance formula
		d = sqrt((x*x + y*y));

		//We set our velocity to move 1/60th of the distance to
		//the target. 60 is arbitrary, I picked it because I intend
		//to run this function once every 60th of a second. We also
		//allow the user to change the camera speed via the speed member
			
		v = (d * speed) / MOVE_SPEED;

		//Keep v above 1 pixel per update, otherwise it may never get to
		//the target. v is an absolute value thanks to the squaring of x
		//and y earlier
		if (v < 1.0f)
			v = 1.0f;

		//Similar triangles to get vx and vy
		vx = x * (v / d);
		vy = y * (v / d);

		//Then update camera's position and we're done
		position.x += vx;
		position.y += vy;
	}
}

sf::IntRect Camera::GetTileBounds(int tileSize)
{
	int x = static_cast<int>(position.x / tileSize);
	int y = static_cast<int>(position.y / tileSize);

	//+1 in case camera size isn't divisible by tileSize
	//And +1 again because these values start at 0, and
	//we want them to start at one
	int w = static_cast<int>(size.x / tileSize + 2);
	int h = static_cast<int>(size.y / tileSize + 2);

	//And +1 again if we're offset from the tile
	if (x % tileSize != 0)
		w++;
	if (y % tileSize != 0)
		h++;

	return sf::IntRect(x, y, w, h);
}