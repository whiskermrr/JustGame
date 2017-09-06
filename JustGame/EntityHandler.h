#pragma once

#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H
#include "state.h"
#include "Player.h"
#include "TileMap.h"

class EntityHandler
{
public:

	EntityHandler(sf::RenderWindow* window);
	void Initiate();
	void Update();
	void Render();
	void checkCollisions();
	~EntityHandler();

private:

	sf::RenderWindow* window;

	Player* player;
	BulletHandler* bulletHandler;
	TileMap* tileMap;
	std::vector<Player*> *playerHandler; // maybe i will create class called PlayerHandler

	

};

#endif

