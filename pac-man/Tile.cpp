#include "Tile.h"
#include <iostream>
Tile::Tile(sf::Texture* texture, float x, float y, float scale)
{
	this->setPelletTexture(texture, 2.0f);
	this->setPosition(x, y);
}

Tile::Tile(sf::Texture* texture, sf::Color color, float x, float y, float scale)
{
	this->setWallTexture(texture, color, scale);
	this->setPosition(x, y);
}

void Tile::setWallTexture(sf::Texture* texture, sf::Color color, float scale)
{
	this->sprite.setTexture(*texture);
	this->sprite.scale(sf::Vector2f(scale, scale));
	this->sprite.setColor(color);
}

void Tile::setPelletTexture(sf::Texture* texture, float scale)
{
	this->sprite.setTexture(*texture);
	this->sprite.scale(sf::Vector2f(scale, scale));
}


void Tile::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

sf::Vector2f Tile::getPosition()
{
	sf::Vector2f vector;
	vector.x = this->sprite.getPosition().x;
	vector.y = this->sprite.getPosition().y;
	return vector;
}

void Tile::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
