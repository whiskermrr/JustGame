#include "EntityHandler.h"


EntityHandler::EntityHandler(sf::RenderWindow* window) : window(window)
{
	
}

void EntityHandler::Initiate()
{
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
	this->player->Render(this->window);
	this->bulletHandler->Render(this->window);
}

EntityHandler::~EntityHandler()
{
	delete this->player;
	delete this->bulletHandler;
	delete this->playerHandler;
	
	this->player = NULL;
	this->bulletHandler = NULL;
	this->playerHandler = NULL;
}