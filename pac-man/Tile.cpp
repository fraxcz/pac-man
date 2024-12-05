#include "Tile.h"
#include <iostream>
Tile::Tile(sf::Texture* texture, float x, float y, float scale, float deg, bool isCollisionable)
{
	setTileTexture(texture, scale);
	setPosition(x, y, deg);
	this->isCollisionable = isCollisionable;

	if (!this->isCollisionable)
	{
		this->eaten = false;
	}
}

Tile::Tile(float x, float y)
{
	setPosition(x, y);
}

void Tile::setPosition(float x, float y, float deg)
{
	this->sprite.setPosition(x, y);

	if(deg > 0.0f)
		this->sprite.rotate(deg);
}

sf::Vector2f Tile::getPosition()
{
	sf::Vector2f vector;
	vector.x = this->sprite.getPosition().x;
	vector.y = this->sprite.getPosition().y;
	return vector;
}

bool Tile::isEaten()
{
	return this->eaten;
}

void Tile::eat()
{
	if (!this->eaten)
		this->eaten = true;
}

void Tile::setTileTexture(sf::Texture *texture, float scale)
{
	this->texture = texture;
	this->sprite.setTexture(*(this->texture));
	this->sprite.scale(sf::Vector2f(scale, scale));
}

bool Tile::IsCollisionalbe()
{
	return this->isCollisionable;
}

void Tile::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
