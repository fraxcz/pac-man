#include "Player.h"

void Player::initVariables()
{
	this->speed = 10.0f;
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
	//Keyboard Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	 this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y - speed));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x - this->speed, this->shape.getPosition().y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x, this->shape.getPosition().y + speed));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->shape.setPosition(sf::Vector2f(this->shape.getPosition().x + this->speed, this->shape.getPosition().y));
}
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
