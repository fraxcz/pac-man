#include "Tile.h"
#include <iostream>
Tile::Tile(sf::Texture* texture, float x, float y, float scale, float deg)
{
	setTileTexture(texture, scale);
	setPosition(x, y, deg);
}


void Tile::setPosition(float x, float y, float deg)
{
	this->sprite.setPosition(x, y);

	if(deg > 0.0f)
		this->sprite.rotate(deg);
}

void Tile::setTileTexture(sf::Texture *texture, float scale)
{
	this->texture = texture;
	this->sprite.setTexture(*(this->texture));
	this->sprite.scale(sf::Vector2f(scale, scale));
}

void Tile::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
