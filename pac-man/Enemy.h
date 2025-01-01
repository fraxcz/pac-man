#pragma once
#include "Entity.h"
enum Color
{
	RED,
	BLUE,
	PINK,
	YELLOW
};
class Enemy: public Entity
{
public:
	Enemy(float tileScale, TileManager* tilemanager, enum Color color);
	void update();
	void render(sf::RenderTarget* target);
};

