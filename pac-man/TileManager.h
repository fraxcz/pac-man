#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Tile.h"
#include <iostream>
#include <vector>
class TileManager
{
private:
	sf::Texture* textures[19];
	std::vector<Tile> tileMap;
	int edible = 0;

public:
	TileManager();
	~TileManager();
	void addTile(sf::Texture *texture, float x, float y, bool isCollisionable = false, float scale = 1.0f, float deg = 0.0f);
	void loadTextures();
	void eat(float x, float y);
	void render(sf::RenderTarget *target);
	bool getTileCollision(float x, float y);
};

