#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.width = 1080;
	this->videoMode.height = 720;
	this->window = new sf::RenderWindow(videoMode, "Pac-man", sf::Style::Close);
	this->window->setFramerateLimit(60);

}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch(this->event.type)
		{
		case sf::Event::Closed:
			window->close();
		}
	}
}

void Game::update()
{
	this->player.update();
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();
	this->player.render(this->window);
	this->window->display();
}
