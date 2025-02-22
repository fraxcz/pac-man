#include "TileManager.h"

void TileManager::loadTextures()
{
	this->wallTexture = new sf::Texture();
	this->wallTexture->loadFromFile("Textures/wall/wall.png");
	this->pelletTexture = new sf::Texture();
	this->pelletTexture->loadFromFile("Textures/Pac-Man/pellet.png");
}
void TileManager::eat(float x, float y)
{
	//TODO: dodìlat eat funkci
	for (int i = 0; i < this->pelletMap.size(); i++)
	{
		if (this->pelletMap.at(i).getPosition().x == x && this->pelletMap.at(i).getPosition().y == y)
			this->pelletMap.erase(pelletMap.begin() + i);
	}
}

bool TileManager::getTileCollision(float x, float y)
{
	for (int i = 0; i < this->tileMap.size(); i++)
	{
		sf::Vector2f pos = tileMap[i].getPosition();
		if (pos.x == x && pos.y == y)
			return true;
	}
	return false;
}

TileManager::TileManager()
{
	this->loadTextures();
	int map[19][19] =
	{
		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 0 , 1 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 0 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 2 , 1 , 2 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 },
		{ 2 , 2 , 2 , 1 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 0 , 1 , 2 , 2 , 2 },
		{ 1 , 1 , 1 , 1 , 0 , 1 , 2 , 1 , 1 , 2 , 1 , 1 , 2 , 1 , 0 , 1 , 1 , 1 , 1 },
		{ 0 , 0 , 0 , 0 , 0 , 2 , 2 , 1 , 2 , 2 , 2 , 1 , 2 , 2 , 0 , 0 , 0 , 0 , 0 },
		{ 1 , 1 , 1 , 1 , 0 , 1 , 2 , 1 , 2 , 2 , 2 , 1 , 2 , 1 , 0 , 1 , 1 , 1 , 1 },
		{ 2 , 2 , 2 , 1 , 0 , 1 , 2 , 1 , 2 , 2 , 2 , 1 , 2 , 1 , 0 , 1 , 2 , 2 , 2 },
		{ 1 , 1 , 1 , 1 , 0 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 0 , 1 , 1 , 1 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 },
		{ 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
		{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
	};

	for (int i = 0; i <= 18; i++)
	{
		for (int j = 0; j <= 18; j++)
		{
			switch (map[i][j])
			{
			case 1:
				this->addTileWall(wallTexture, sf::Color(0, 0, 200, 255), j * 32, i * 32, 2.0f);
				break;

			case 0:
				this->addTilePellet(pelletTexture, j * 32, i * 32, 2.0f);
				this->edible += 1;
				break;
			}

		}
	}
}

void TileManager::addTileWall(sf::Texture* texture, sf::Color color, float x, float y, float scale)
{
	this->tileMap.push_back(Tile(texture, color, x, y, scale));
}

void TileManager::addTilePellet(sf::Texture* texture, float x, float y, float scale)
{
	this->pelletMap.push_back(Tile(texture, x, y, scale));
}

void TileManager::render(sf::RenderTarget* target)
{
	for (int i = 0; i < tileMap.size(); i++)
	{
		this->tileMap[i].render(target);
	}
	for (int i = 0; i < this->pelletMap.size(); i++)
	{
		this->pelletMap[i].render(target);
	}
}
TileManager::~TileManager()
{
	delete this->wallTexture;
	delete this->pelletTexture;
}
