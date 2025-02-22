#include "Enemy.h"
#include "Game.h"
Enemy::Enemy(float x, float y, float tileScale, TileManager *tilemanager, Color color, Game* game) : Entity(tileScale, tilemanager)
{
	std::string filepaths[8];
	switch (color)
	{
		case RED:
			filepaths[0] = "Textures/Ghosts/Red/up-1.png";
			filepaths[1] = "Textures/Ghosts/Red/up-2.png";
			filepaths[2] = "Textures/Ghosts/Red/right-1.png";
			filepaths[3] = "Textures/Ghosts/Red/right-2.png";
			filepaths[4] = "Textures/Ghosts/Red/down-1.png";
			filepaths[5] = "Textures/Ghosts/Red/down-2.png";
			filepaths[6] = "Textures/Ghosts/Red/left-1.png";
			filepaths[7] = "Textures/Ghosts/Red/left-2.png";
			break;

		case BLUE:
			filepaths[0] = "Textures/Ghosts/Blue/up-1.png";
			filepaths[1] = "Textures/Ghosts/Blue/up-2.png";
			filepaths[2] = "Textures/Ghosts/Blue/right-1.png";
			filepaths[3] = "Textures/Ghosts/Blue/right-2.png";
			filepaths[4] = "Textures/Ghosts/Blue/down-1.png";
			filepaths[5] = "Textures/Ghosts/Blue/down-2.png";
			filepaths[6] = "Textures/Ghosts/Blue/left-1.png";
			filepaths[7] = "Textures/Ghosts/Blue/left-2.png";
			break;

		case PINK:
			filepaths[0] = "Textures/Ghosts/Pink/up-1.png";
			filepaths[1] = "Textures/Ghosts/Pink/up-2.png";
			filepaths[2] = "Textures/Ghosts/Pink/right-1.png";
			filepaths[3] = "Textures/Ghosts/Pink/right-2.png";
			filepaths[4] = "Textures/Ghosts/Pink/down-1.png";
			filepaths[5] = "Textures/Ghosts/Pink/down-2.png";
			filepaths[6] = "Textures/Ghosts/Pink/left-1.png";
			filepaths[7] = "Textures/Ghosts/Pink/left-2.png";
			break;

		case ORANGE:
			filepaths[0] = "Textures/Ghosts/Orange/up-1.png";
			filepaths[1] = "Textures/Ghosts/Orange/up-2.png";
			filepaths[2] = "Textures/Ghosts/Orange/right-1.png";
			filepaths[3] = "Textures/Ghosts/Orange/right-2.png";
			filepaths[4] = "Textures/Ghosts/Orange/down-1.png";
			filepaths[5] = "Textures/Ghosts/Orange/down-2.png";
			filepaths[6] = "Textures/Ghosts/Orange/left-1.png";
			filepaths[7] = "Textures/Ghosts/Orange/left-2.png";
			break;
	}
	this->initModel(x, y, filepaths);
	this->game = game;
}

void Enemy::update()
{
	// ai generated, idk how pathfinding works lol
	// A function for "Greedy AI"
	sf::Vector2f playerPos = this->game->getPlayerPosition();
	Direction playerDirection[2] = {NONE, NONE};

	// Determination of priority directions of movement
	if (this->getEntityPosition().x > playerPos.x)
		playerDirection[0] = LEFT;
	else if (this->getEntityPosition().x < playerPos.x)
		playerDirection[0] = RIGHT;

	if (this->getEntityPosition().y > playerPos.y)
		playerDirection[1] = UP;
	else if (this->getEntityPosition().y < playerPos.y)
		playerDirection[1] = DOWN;

	// Primary movement along the X axis, as long as there's no collision
	if (playerDirection[0] != NONE && !this->collision(playerDirection[0])) {
		this->dir = playerDirection[0];
	}
	// If X axis is blocked, try Y axis
	else if (playerDirection[1] != NONE && !this->collision(playerDirection[1])) {
		this->dir = playerDirection[1];
	}
	// If both directions are blocked, we'll try the opposite direction
	else {
		if (!this->collision(LEFT)) this->dir = LEFT;
		else if (!this->collision(RIGHT)) this->dir = RIGHT;
		else if (!this->collision(UP)) this->dir = UP;
		else if (!this->collision(DOWN)) this->dir = DOWN;
	}
	this->updateModel();
}

void Enemy::render(sf::RenderTarget* target)
{
	this->renderModel(target);
}

