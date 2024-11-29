#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	void initVariables(float tileScale);
	void initPlayerModel();
	enum Direction dir;
	float speed;
	float tileScale;
public:
	Player(float tileScale);
	virtual ~Player();
	void update();
	void render(sf::RenderTarget* target);
};
