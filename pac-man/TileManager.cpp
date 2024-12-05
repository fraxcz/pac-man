#include "TileManager.h"

void TileManager::loadTextures()
{
std::string textureFiles[16] = {
		"Textures/Tiles/Background.png",
		"Textures/Tiles/wall-upright.png",
		"Textures/Tiles/wall-upleft.png",
		"Textures/Tiles/wall-downright.png",
		"Textures/Tiles/wall-downleft.png",
		"Textures/Tiles/wall-straightup.png",
		"Textures/Tiles/wall-straightright.png",
		"Textures/Tiles/wall-down.png",
		"Textures/Tiles/wall-up.png",
		"Textures/Tiles/wall-left.png",
		"Textures/Tiles/wall-right.png",
		"Textures/Tiles/wall-left-up-right.png",
		"Textures/Tiles/wall-up-right-down.png",
		"Textures/Tiles/wall-right-down-left.png",
		"Textures/Tiles/wall-down-left-up.png",
		"Textures/Pac-Man/pellet.png"
};
for (int i = 0; i < 16; i++)
{
	textures[i] = new sf::Texture();
	if (!this->textures[i]->loadFromFile(textureFiles[i]))
	{
		std::cout << "File not found." << std::endl;
	}
}

}
void TileManager::render(sf::RenderTarget* target)
{
	for (int i = 0; i < tileMap.size(); i++)
	{
		this->tileMap[i].render(target);
	}
}

bool TileManager::getTile(float x, float y)
{
	for (int i = 0; i < this->tileMap.size(); i++)
	{
		sf::Vector2f pos = tileMap[i].getPosition();
		if (tileMap[i].IsCollisionalbe() && pos.x == x && pos.y == y)
		{
			return true;
		}
	}
	return false;
}

void TileManager::addTile(sf::Texture* texture, float x, float y,bool isCollisionable, float scale, float deg)
{

	this->tileMap.push_back(Tile(texture, x, y, scale, deg, isCollisionable));
}

TileManager::TileManager()
{
	this->loadTextures();
	char map[20][20] =
	{
		{'1','-','-','-','-','-','-','-','7','-','-','-','-','-','-','-','-','-','-','4'},
		{'|','0','0','0','0','0','0','0','|','0','0','0','0','0','0','0','0','0','0','|'},
		{'|','0','d','0','1','-','4','0','|','0','1','-','-','4','0','1','-','4','0','|'},
		{'|','0','|','0','2','-','3','0','u','0','2','-','-','3','0','2','-','3','0','|'},
		{'|','0','u','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','|'},
		{'|','0','0','0','r','l','0','r','-','l','0','r','-','l','0','r','-','l','0','|'},
		{'|','0','d','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','|'},
		{'2','-','5','4','0','d','0','1','l','0','r','4','0','1','4','0','1','-','-','3'},
		{'1','-','-','3','0','u','0','|','s','s','s','|','0','|','|','0','2','-','-','4'},
		{'|','0','0','0','0','0','0','|','s','s','s','|','0','|','|','0','0','0','0','|'},
		{'2','-','-','4','0','d','0','|','s','s','s','|','0','|','|','0','1','-','-','3'},
		{'1','-','7','3','0','u','0','2','-','-','-','3','0','2','3','0','2','-','-','4'},
		{'|','0','u','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','|'},
		{'|','0','0','0','d','0','r','-','l','0','d','0','d','0','d','0','1','l','0','|'},
		{'|','0','r','-','3','0','0','0','0','0','|','0','|','0','|','0','|','0','0','|'},
		{'|','0','0','0','0','0','r','-','7','-','3','0','|','0','u','0','u','0','r','8'},
		{'|','0','1','-','4','0','0','0','|','0','0','0','|','0','0','0','0','0','0','|'},
		{'|','0','2','-','5','-','l','0','u','0','r','-','5','-','-','-','-','l','0','|'},
		{'|','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','|'},
		{'2','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','3'}
	};

	for(int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			switch (map[i][j])
			{
			case '-':
				this->addTile(textures[6], (float) j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '|':
				this->addTile(textures[5], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '1':
				this->addTile(textures[3], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '2':
				this->addTile(textures[1], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '3':
				this->addTile(textures[2], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '4':
				this->addTile(textures[4], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case 'd':
				this->addTile(textures[7], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case 'u':
				this->addTile(textures[8], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case 'l':
				this->addTile(textures[9], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case 'r':
				this->addTile(textures[10], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '5':
				this->addTile(textures[11], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '6':
				this->addTile(textures[12], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '7':
				this->addTile(textures[13], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '8':
				this->addTile(textures[14], (float)j * 32.0f, (float)i * 32.0f, true, 2.0f);
				break;
			case '0':
				this->addTile(textures[15], (float)j * 32.0f, (float)i * 32.0f, false, 2.0f);
				break;
			}
		}
}
