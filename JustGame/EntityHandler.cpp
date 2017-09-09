#include "EntityHandler.h"


EntityHandler::EntityHandler(sf::RenderWindow* window) : window(window)
{
	
}

void EntityHandler::Initiate()
{
	this->tileMap = new TileMap("resources/tile.txt");
	this->bulletHandler = new BulletHandler();
	this->playerHandler = new std::vector<Player*>();
	this->player = new Player(bulletHandler);
	this->playerHandler->push_back(this->player);
}


void EntityHandler::Update()
{
	this->player->Update();
	this->bulletHandler->Update();
}

void EntityHandler::Render()
{
	this->tileMap->Render(this->window);
	this->player->Render(this->window);
	this->bulletHandler->Render(this->window);
}

void EntityHandler::checkCollisions()
{
	std::vector<Tile*> *playerTiles = new std::vector<Tile*>();

	int x = player->getPosition().x / 32;
	int y = player->getPosition().y / 32;

	playerTiles->push_back(this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x));
	playerTiles->push_back(this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x + 1));
	playerTiles->push_back(this->tileMap->getTiles()->at((y + 1) * this->tileMap->getColumns() + x));
	playerTiles->push_back(this->tileMap->getTiles()->at((y + 1) * this->tileMap->getColumns() + x + 1));
	playerTiles->push_back(this->tileMap->getTiles()->at((y + 2) * this->tileMap->getColumns() + x));
	playerTiles->push_back(this->tileMap->getTiles()->at((y + 2) * this->tileMap->getColumns() + x + 1));

	for (int i = 0; i != playerTiles->size(); i++)
	{
		if (playerTiles->at(i)->isWall() && player->checkCollisionWithWall(playerTiles->at(i)))
		{
			if (i == 0 || i == 1)
				player->setMoveUp(false);

			if (i == 2)
				player->setMoveLeft(false);

			if (i == 3)
				player->setMoveRight(false);

			if (i == 4 || i == 5)
				player->setMoveDown(false);
			
		}

		else
		{
			if (i == 0 || i == 1)
				player->setMoveUp(true);

			if (i == 2)
				player->setMoveLeft(true);

			if (i == 3)
				player->setMoveRight(true);

			if (i == 4 || i == 5)
				player->setMoveDown(true);
		}
	}

	for (std::vector<Bullet*>::iterator bullet = this->bulletHandler->getBullets()->begin();
		bullet != this->bulletHandler->getBullets()->end(); )
	{
		int x = (*bullet)->getPosition().x / 32;
		int y = (*bullet)->getPosition().y / 32;

		if (this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x)->isWall())
		{
			if ((*bullet)->checkCollisionWithWall(this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x)))
			{
				delete *bullet;
				bullet = this->bulletHandler->getBullets()->erase(bullet);
			}

			else
				bullet++;
		}
		else
			bullet++;
	}
}

EntityHandler::~EntityHandler()
{
	delete this->player;
	delete this->bulletHandler;
	delete this->playerHandler;
	delete this->tileMap;
	
	this->player = NULL;
	this->bulletHandler = NULL;
	this->playerHandler = NULL;
	this->tileMap = NULL;
}