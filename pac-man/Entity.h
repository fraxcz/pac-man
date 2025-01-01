#pragma once
#include <iostream>
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

class Entity
{
public:
	Entity(float tileScale, TileManager* tilemanager);
	virtual ~Entity();

protected:
	float speed;
	float tileScale;
	enum Direction dir;
	void initModel(std::string filepaths[8]);
	void renderModel(sf::RenderTarget* target);
	void updateModel();
	void eat();
	bool collision(Direction dir);
private:
	sf::Sprite sprite;
	sf::Texture *texture_up[2];
	sf::Texture *texture_down[2];
	sf::Texture *texture_left[2];
	sf::Texture *texture_right[2];
	TileManager* tilemanager;
	bool canChangeDirection = false;
	void initVariables(float tileScale);
	enum Direction spriteDir;
};
