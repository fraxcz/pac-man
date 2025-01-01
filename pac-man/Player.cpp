#include "Entity.h"
#include <iostream>
#include "Player.h"


Player::Player(float tileScale, TileManager* tilemanager) : Entity(tileScale, tilemanager)
{
	std::string filepaths[8] =
	{
		"Textures/Pac-Man/pacman-up-closed.png",
		"Textures/Pac-Man/pacman-up-open.png",
		"Textures/Pac-Man/pacman-right-closed.png",
		"Textures/Pac-Man/pacman-right-open.png",
		"Textures/Pac-Man/pacman-down-closed.png",
		"Textures/Pac-Man/pacman-down-open.png",
		"Textures/Pac-Man/pacman-left-closed.png",
		"Textures/Pac-Man/pacman-left-open.png"
	};
	this->initModel(filepaths);
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->dir = UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->dir = RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->dir = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->dir = LEFT;
	this->updateModel();
	this->eat();
}

void Player::render(sf::RenderTarget* target)
{
	this->renderModel(target);
}
