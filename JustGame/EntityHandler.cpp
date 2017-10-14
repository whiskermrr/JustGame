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
	this->playerTiles = new std::vector<Tile*>();
	this->player->setTiles(this->playerTiles);
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
	int x = player->getPosition().x / 32;
	int y = player->getPosition().y / 32;

	this->player->tiles->push_back(this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x));
	this->player->tiles->push_back(this->tileMap->getTiles()->at(y * this->tileMap->getColumns() + x + 1));
	this->player->tiles->push_back(this->tileMap->getTiles()->at((y + 1) * this->tileMap->getColumns() + x));
	this->player->tiles->push_back(this->tileMap->getTiles()->at((y + 1) * this->tileMap->getColumns() + x + 1));
	this->player->tiles->push_back(this->tileMap->getTiles()->at((y + 2) * this->tileMap->getColumns() + x));
	this->player->tiles->push_back(this->tileMap->getTiles()->at((y + 2) * this->tileMap->getColumns() + x + 1));

	this->player->checkCollisionWithWall();

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

	this->player->tiles->clear();
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