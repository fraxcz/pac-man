#include "Enemy.h"

Enemy::Enemy(float tileScale, TileManager *tilemanager, enum Color color) : Entity(tileScale, tilemanager)
{
	std::string filepaths[8];
	switch (color)
	{
		case RED:
			filepaths[0] = "Textures/Ghosts/Red/up-1.png";
			filepaths[1] = "Textures/Ghosts/Red/up-2.png";
			filepaths[2] = "Textures/Ghosts/Red/right-1.png";
			filepaths[3] = "Textures/Ghosts/Red/right-2.png";
			filepaths[4] = "Textures/Ghosts/Red/down-1.png";
			filepaths[5] = "Textures/Ghosts/Red/down-2.png";
			filepaths[6] = "Textures/Ghosts/Red/left-1.png";
			filepaths[7] = "Textures/Ghosts/Red/left-2.png";
			break;

		case BLUE:
			filepaths[0] = "Textures/Ghosts/Blue/up-1.png";
			filepaths[1] = "Textures/Ghosts/Blue/up-2.png";
			filepaths[2] = "Textures/Ghosts/Blue/right-1.png";
			filepaths[3] = "Textures/Ghosts/Blue/right-2.png";
			filepaths[4] = "Textures/Ghosts/Blue/down-1.png";
			filepaths[5] = "Textures/Ghosts/Blue/down-2.png";
			filepaths[6] = "Textures/Ghosts/Blue/left-1.png";
			filepaths[7] = "Textures/Ghosts/Blue/left-2.png";
			break;

		case PINK:
			filepaths[0] = "Textures/Ghosts/Pink/up-1.png";
			filepaths[1] = "Textures/Ghosts/Pink/up-2.png";
			filepaths[2] = "Textures/Ghosts/Pink/right-1.png";
			filepaths[3] = "Textures/Ghosts/Pink/right-2.png";
			filepaths[4] = "Textures/Ghosts/Pink/down-1.png";
			filepaths[5] = "Textures/Ghosts/Pink/down-2.png";
			filepaths[6] = "Textures/Ghosts/Pink/left-1.png";
			filepaths[7] = "Textures/Ghosts/Pink/left-2.png";
			break;

		case YELLOW:
			filepaths[0] = "Textures/Ghosts/Yellow/up-1.png";
			filepaths[1] = "Textures/Ghosts/Yellow/up-2.png";
			filepaths[2] = "Textures/Ghosts/Yellow/right-1.png";
			filepaths[3] = "Textures/Ghosts/Yellow/right-2.png";
			filepaths[4] = "Textures/Ghosts/Yellow/down-1.png";
			filepaths[5] = "Textures/Ghosts/Yellow/down-2.png";
			filepaths[6] = "Textures/Ghosts/Yellow/left-1.png";
			filepaths[7] = "Textures/Ghosts/Yellow/left-2.png";
			break;
	}
	this->initModel(filepaths);
}

void Enemy::update()
{
	this->dir = static_cast<Direction>(std::rand() % 4);
	std::cout << this->dir << std::endl;
	this->updateModel();
}

void Enemy::render(sf::RenderTarget* target)
{
	this->renderModel(target);
}

