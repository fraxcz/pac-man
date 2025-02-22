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
	sf::Texture* wallTexture;
	sf::Texture* pelletTexture;
	std::vector<Tile> tileMap;
	std::vector<Tile> pelletMap;
	int edible = 0;

public:
	TileManager();
	~TileManager();
	void addTileWall(sf::Texture *texture, sf::Color color, float x, float y, float scale = 1.0f);
	void addTilePellet(sf::Texture* texture, float x, float y, float scale = 1.0f);
	void loadTextures();
	void eat(float x, float y);
	void render(sf::RenderTarget *target);
	bool getTileCollision(float x, float y);
};

