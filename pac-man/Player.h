#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, float tileScale, TileManager* tilemanager);
	void update();
	void render(sf::RenderTarget* target);
	sf::Vector2f getPosition();
};