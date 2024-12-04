#include "Player.h"

void Player::initVariables(float tileScale)
{
	//loading texture
	if (!this->texture.loadFromFile("Textures/Pac-Man/Pac-Man.png"))
		std::cout << "Error while loading texture: Player." << std::endl;
	this->speed = 16.0f;
	this->dir = RIGHT;
	this->tileScale = tileScale;
}

void Player::initPlayerModel()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprites
	this->sprite.scale(sf::Vector2f(this->tileScale, this->tileScale));

}

Player::Player(float tileScale)
{
	this->initVariables(tileScale);
	this->initPlayerModel();
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


	switch (this->dir)
	{
	case UP:
		this->sprite.move(sf::Vector2f(.0f, -speed));
		break;
	case RIGHT:
		this->sprite.move(sf::Vector2f(speed, .0f));
		break;
	case DOWN:
		this->sprite.move(sf::Vector2f(.0f, speed));
		break;
	case LEFT:
		this->sprite.move(sf::Vector2f(-speed, .0f));
		break;
	}
}
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
