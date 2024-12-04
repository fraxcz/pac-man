#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Tile
{
private:
	sf::Sprite sprite;
	sf::Texture* texture;
public:
	Tile(sf::Texture *texture, float x, float y, float scale = 1.0f, float deg = 0.0f);
	void render(sf::RenderTarget* target);
	void setPosition(float x, float y, float deg = 0.0f);
	void setTileTexture(sf::Texture *texture, float scale = 1.0f);
};

