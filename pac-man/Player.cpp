#include "Player.h"
void Player::initVariables(float tileScale)
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
	//loading texture
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i < 2)
			{
				this->texture_up[j] = new sf::Texture();
				if (!this->texture_up[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 4)
			{
				this->texture_right[j] = new sf::Texture();
				if (!this->texture_right[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 6)
			{
				this->texture_down[j] = new sf::Texture();
				if (!this->texture_down[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 8)
			{
				this->texture_left[j] = new sf::Texture();
				if (!this->texture_left[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}
		}

	}
	this->speed = 16.0f;
	this->dir = RIGHT;
	this->spriteDir = RIGHT;
	this->tileScale = tileScale;
}

void Player::initPlayerModel()
{
	//Set the texture to the sprite
	this->sprite.setTexture(*(this->texture_right[0]));

	//Resize the sprites
	this->sprite.scale(sf::Vector2f(this->tileScale, this->tileScale));
	this->sprite.setPosition(32.0f, 32.0f);

}

Player::~Player()
{
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


	//change direction
	if (canChangeDirection)
	{
		switch (this->dir)
		{
		case UP:
			this->spriteDir = UP;
			break;
		case RIGHT:
			this->spriteDir = RIGHT;
			break;
		case DOWN:
			this->spriteDir = DOWN;
			break;
		case LEFT:
			this->spriteDir = LEFT;
			break;
		}
	}
	switch (this->spriteDir)
	{
	case UP:
		if (!this->tilemanager->getTile(this->sprite.getPosition().x, this->sprite.getPosition().y - 32.f))
		{
			this->sprite.move(0.0f, -speed);
			if (!canChangeDirection)
				this->sprite.setTexture(*texture_up[0]);
			else
				this->sprite.setTexture(*texture_up[1]);
		}
		break;
	case RIGHT:
		if (!this->tilemanager->getTile(this->sprite.getPosition().x + 32.0f, this->sprite.getPosition().y))
			this->sprite.move(speed, 0.0f);
		{
			if (!canChangeDirection)
				this->sprite.setTexture(*texture_right[0]);
			else
				this->sprite.setTexture(*texture_right[1]);
		}
		break;
	case DOWN:
		if (!this->tilemanager->getTile(this->sprite.getPosition().x, this->sprite.getPosition().y + 32.0f))
		{
			this->sprite.move(0.0f, speed);
			if (!canChangeDirection)
				this->sprite.setTexture(*texture_down[0]);
			else
				this->sprite.setTexture(*texture_down[1]);
		}
		break;
	case LEFT:
		if (!this->tilemanager->getTile(this->sprite.getPosition().x - 32.0f, this->sprite.getPosition().y))
		{
		this->sprite.move(-speed, 0.0f);
		if (!canChangeDirection)
			this->sprite.setTexture(*texture_left[0]);
		else
			this->sprite.setTexture(*texture_left[1]);
		}
		break;
	}

	if (canChangeDirection)
	{
		canChangeDirection = false;
	}
	else
		canChangeDirection = true;
}
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

Player::Player(float tileScale, TileManager* tilemanager)
{
	this->tilemanager = tilemanager;
	this->initVariables(tileScale);
	this->initPlayerModel();
	this->canChangeDirection = true;
}
