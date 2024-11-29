#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Player
{
private:
	sf::RectangleShape shape;
	void initVariables();
	void initShape(sf::Vector2f position);
	float speed;

public:
	Player(float x = .0f, float y = .0f);
	virtual ~Player();
	void update();
	void render(sf::RenderTarget* target);
};
