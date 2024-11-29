#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	Player player;
	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();
	const bool running() const;
	void pollEvents();
	void update();
	void render();
};

