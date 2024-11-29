#include "Player.h"

void Player::initVariables()
{
	this->speed = 1.0f;
	this->dir = RIGHT;
}

void Player::initShape(sf::Vector2f position)
{
	this->shape.setFillColor(sf::Color(255, 0, 0, 255));
	this->shape.setSize(sf::Vector2f(100.0f, 100.0f));
	this->shape.setPosition(position);
}

Player::Player(float x, float y)
{
	this->initVariables();
	this->initShape(sf::Vector2f(x, y));
}

Player::~Player()
{
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dir = UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dir = RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dir = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dir = LEFT;


	switch (dir)
	{
	case UP:
		this->shape.move(sf::Vector2f(.0f, -speed));
		break;
	case RIGHT:
		this->shape.move(sf::Vector2f(speed, .0f));
		break;
	case DOWN:
		this->shape.move(sf::Vector2f(.0f, speed));
		break;
	case LEFT:
		this->shape.move(sf::Vector2f(-speed, .0f));
		break;
	}
}
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
