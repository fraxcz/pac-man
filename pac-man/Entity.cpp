#include "Entity.h"
void Entity::initVariables(float tileScale)
{
	//init class textures
	for (int i = 0; i < 2; i++)
	{
		this->texture_up[i] = new sf::Texture();
		this->texture_right[i] = new sf::Texture();
		this->texture_down[i] = new sf::Texture();
		this->texture_left[i] = new sf::Texture();
	}
	this->speed = 16.0f;
	this->dir = RIGHT;
	this->spriteDir = RIGHT;
	this->tileScale = tileScale;
}
//load textures and set it to the sprite
void Entity::initModel(float x, float y, std::string filepaths[8])
{
	//loading textures from a file (each entity contains 2 frames to each direction)
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i < 2)
			{
				if (!this->texture_up[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 4)
			{
				if (!this->texture_right[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 6)
			{
				if (!this->texture_down[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}

			else if (i < 8)
			{
				if (!this->texture_left[j]->loadFromFile(filepaths[i + j]))
				{
					std::cout << "File not found." << std::endl;
				}
			}
		}

	}

	//Set the texture to the sprite
	this->sprite.setTexture(*(this->texture_right[0]));

	//Resize the sprites
	this->sprite.scale(this->tileScale, this->tileScale);

	//Set position
	this->sprite.setPosition(x, y);

}

Entity::~Entity()
{
	for (int i = 0; i < 2; ++i) {
		delete texture_up[i];
		delete texture_right[i];
		delete texture_down[i];
		delete texture_left[i];
	}
}

void Entity::updateModel()
{
	//change direction
	if (canChangeDirection)
	{
		switch (this->dir)
		{
		case UP:
			if(!collision(UP))
				this->spriteDir = UP;
			break;
		case RIGHT:
			if (!collision(RIGHT))
				this->spriteDir = RIGHT;
			break;
		case DOWN:
			if (!collision(DOWN))
				this->spriteDir = DOWN;
			break;
		case LEFT:
			if (!collision(LEFT))
				this->spriteDir = LEFT;
			break;
		}
	}
	switch (this->spriteDir)
	{
	case UP:
		if (!collision(UP))
		{
			this->sprite.move(0.0f, -speed);
			if (!canChangeDirection)
				this->sprite.setTexture(*texture_up[0]);
			else
				this->sprite.setTexture(*texture_up[1]);
		}
		break;
	case RIGHT:
		if (!collision(RIGHT))
		{ 
			this->sprite.move(speed, 0.0f);
			if (!canChangeDirection)
				this->sprite.setTexture(*texture_right[0]);
			else
				this->sprite.setTexture(*texture_right[1]);
		}
		break;
	case DOWN:
		if (!collision(DOWN))
		{
			this->sprite.move(0.0f, speed);

			if (!canChangeDirection)
				this->sprite.setTexture(*texture_down[0]);
			else
				this->sprite.setTexture(*texture_down[1]);
		}
		break;
	case LEFT:
		if (!collision(LEFT))
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
		canChangeDirection = false;

	else
		canChangeDirection = true;
}
void Entity::eat()
{
	if (canChangeDirection)
	{
		this->tilemanager->eat(this->sprite.getPosition().x, this->sprite.getPosition().y);
	}
}
void Entity::renderModel(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

bool Entity::collision(Direction dir)
{
	switch (dir)
	{
	case UP:
		if (this->tilemanager->getTileCollision(this->sprite.getPosition().x, this->sprite.getPosition().y - 32.f))
			return true;
		return false;
		break;

	case RIGHT:
		if (this->tilemanager->getTileCollision(this->sprite.getPosition().x + 32.0f, this->sprite.getPosition().y))
			return true;
		return false;
		break;

	case DOWN:
		if (this->tilemanager->getTileCollision(this->sprite.getPosition().x, this->sprite.getPosition().y + 32.0f))
			return true;
		return false;
		break;

	case LEFT:
		if (this->tilemanager->getTileCollision(this->sprite.getPosition().x - 32.0f, this->sprite.getPosition().y))
			return true;
		return false;
		break;
	}
	return true;
}

sf::Vector2f Entity::getEntityPosition()
{
	return this->sprite.getPosition();
}

Entity::Entity(float tileScale, TileManager* tilemanager)
{
	this->tilemanager = tilemanager;
	this->initVariables(tileScale);
	this->canChangeDirection = true;
}
