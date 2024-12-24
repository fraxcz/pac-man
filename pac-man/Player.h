#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "TileManager.h"

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
	sf::Texture *texture_up[2];
	sf::Texture *texture_down[2];
	sf::Texture *texture_left[2];
	sf::Texture *texture_right[2];
	TileManager* tilemanager;
	bool canChangeDirection = false;
	bool collision(Direction dir);
	void initVariables(float tileScale);
	void initPlayerModel();
	enum Direction dir;
	enum Direction spriteDir;
	float speed;
	float tileScale;
public:
	Player(float tileScale, TileManager* tilemanager);
	virtual ~Player();
	void update();
	void render(sf::RenderTarget* target);
};
