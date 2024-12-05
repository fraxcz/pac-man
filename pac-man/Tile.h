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
	bool isCollisionable;
	bool eaten = true;
public:
	Tile(sf::Texture *texture, float x, float y, float scale = 1.0f, float deg = 0.0f, bool isCollisionable = false);
	Tile(float x, float y);
	void render(sf::RenderTarget* target);
	void setPosition(float x, float y, float deg = 0.0f);
	sf::Vector2f getPosition();
	bool isEaten();
	void eat();
	void setTileTexture(sf::Texture *texture, float scale = 1.0f);
	bool IsCollisionalbe();
};

