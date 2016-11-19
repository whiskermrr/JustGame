#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	this->tileMap = new TileMap("resources/tile.txt");
	this->bulletHandler = new BulletHandler();
	this->playerOne = new Player(bulletHandler);
}

void mainGame::Render(sf::RenderWindow* window)
{
	this->tileMap->Render(window);
	this->playerOne->Render(window);
	this->bulletHandler->Render(window);
}

void mainGame::Update(sf::RenderWindow* window)
{
	this->playerOne->Update();
	this->bulletHandler->Update(window);
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete this->tileMap;
	delete this->playerOne;
	delete this->bulletHandler;
	delete this->playerOne;
}

void mainGame::Reset(sf::RenderWindow* window)
{
	
}
