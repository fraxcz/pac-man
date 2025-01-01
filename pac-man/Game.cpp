#include "Game.h"
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.width = TILESIZE * NUMBEROFTILES;
	this->videoMode.height = TILESIZE * NUMBEROFTILES;
	this->window = new sf::RenderWindow(videoMode, "Pac-man", sf::Style::Close);
	this->window->setFramerateLimit(2);

}
void Game::initEntities()
{
	this->tileManager = new TileManager();
	this->player = new Player(TILESCALE, this->tileManager);
	this->enemy = new Enemy(TILESCALE, this->tileManager, RED);
}

Game::Game()
{
	this->initEntities();
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->enemy;
	delete this->tileManager;
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
	this->player->update();
	this->enemy->update();
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();
	this->tileManager->render(this->window);
	this->enemy->render(this->window);
	this->player->render(this->window);
	this->window->display();
}
