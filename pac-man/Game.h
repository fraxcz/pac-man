#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "TileManager.h"
#define ORIGINALTILESIZE 16.0f
#define TILESCALE 2.0f
#define TILESIZE ORIGINALTILESIZE*TILESCALE
#define NUMBEROFTILES 20
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	Player *player;
	TileManager *tileManager;
	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();
	const bool running() const;
	void pollEvents();
	void update();
	void render();
	void initEntities();
};

