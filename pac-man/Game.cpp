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
	this->window->setFramerateLimit(5);

}
void Game::initEntities()
{
	this->tileManager = new TileManager();
	this->player = new Player(32.0f, 32.0f, TILESCALE, this->tileManager);
	this->enemies[0] = new Enemy(9.0f * 32.0f, 8.0f * 32.0f, TILESCALE, this->tileManager, BLUE, this);
	this->enemies[1] = new Enemy(9.0f * 32.0f, 8.0f * 32.0f, TILESCALE, this->tileManager, ORANGE, this);
	this->enemies[2] = new Enemy(9.0f * 32.0f, 8.0f * 32.0f, TILESCALE, this->tileManager, PINK, this);
	this->enemies[3] = new Enemy(9.0f * 32.0f, 8.0f * 32.0f, TILESCALE, this->tileManager, RED, this);
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
	for (int i = 0; i < 4; i++)
	{
		delete this->enemies[i];
	}
	delete this->tileManager;
}

bool Game::running() const
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
	for (int i = 0; i < 4; i++)
	{
		this->enemies[i]->update();
	}
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();
	this->tileManager->render(this->window);
	for (int i = 0; i < 4; i++)
	{
		this->enemies[i]->render(this->window);
	}
	this->player->render(this->window);
	this->window->display();
}

sf::Vector2f Game::getPlayerPosition()
{
	return this->player->getPosition();
}