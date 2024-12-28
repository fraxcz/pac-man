#pragma once
#include "Entity.h";
class Player : public Entity
{
public:
	Player(float tileScale, TileManager* tilemanager);
	void update();
	void render(sf::RenderTarget* target);
};

