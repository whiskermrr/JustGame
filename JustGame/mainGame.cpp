#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	this->entityHandler = new EntityHandler(window);
	this->entityHandler->Initiate();
}

void mainGame::Render(sf::RenderWindow* window)
{
	this->entityHandler->Render();
}

void mainGame::Update(sf::RenderWindow* window)
{
	this->entityHandler->Update();
	this->entityHandler->checkCollisions();
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete this->entityHandler;

	this->entityHandler = NULL;
}

void mainGame::Reset(sf::RenderWindow* window)
{
	
}
