#pragma once
#include "Entity.h"
enum Color
{
	RED,
	BLUE,
	PINK,
	ORANGE
};

class Game;

class Enemy : public Entity
{

public:
	Enemy(float x, float y, float tileScale, TileManager* tilemanager, Color color, Game* game);
	void update();
	void render(sf::RenderTarget* target);

private:
	Game* game;
};