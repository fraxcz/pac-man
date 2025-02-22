#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "TileManager.h"
#include "Enemy.h"
constexpr float ORIGINALTILESIZE = 16.0f;
constexpr float TILESCALE = 2.0f;
constexpr float TILESIZE = ORIGINALTILESIZE * TILESCALE;
constexpr float NUMBEROFTILES = 19.0f;
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	Player *player;
	TileManager *tileManager;
	Enemy* enemies[4];
	void initVariables();
	void initEntities();
	void initWindow();
	void pollEvents();

public:
	Game();
	virtual ~Game();
	bool running() const;
	void update();
	void render();
	sf::Vector2f getPlayerPosition();
};

