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
// TODO fix this collision and make it better (preformance)
void EntityHandler::checkCollisions()
{
	/*
	for (std::vector<Bullet*>::iterator bullet = this->bulletHandler->getBullets()->begin();
		bullet != this->bulletHandler->getBullets()->end();)
	{
		sf::Vector2f bulletPosition = (*bullet)->getPosition();
		int x = bulletPosition.x / 32;
		int y = bulletPosition.y / 32;

		if (this->tileMap->getTiles()->at(y * 26 + x)->isWall())
		{
			if ((*bullet)->CheckCollision(this->tileMap->getTiles()->at(y * 26 + x)))
			{
				std::cout << "Collision" << std::endl;
				delete *bullet;
				bullet = this->bulletHandler->getBullets()->erase(bullet);
			}

			else
				bullet++;
		}

		else bullet++;
	}
	*/
	
	
	for (std::vector<Tile*>::iterator tile = this->tileMap->getTiles()->begin(); tile != this->tileMap->getTiles()->end(); tile++)
	{
		if ((*tile)->isWall())
		{
		/*
			if (this->player->checkCollisionWithWall(*tile))
			{
				//this->player->setMove(false);
				std::cout << "Collision" << std::endl;
			}
		*/
			for (std::vector<Bullet*>::iterator bullet = this->bulletHandler->getBullets()->begin();
				bullet != this->bulletHandler->getBullets()->end();)
			{
				if ((*bullet)->CheckCollision(*tile))
				{
					delete *bullet;
					bullet = this->bulletHandler->getBullets()->erase(bullet);
				}

				else
					bullet++;
			}

		}
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