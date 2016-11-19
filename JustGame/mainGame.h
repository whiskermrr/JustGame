#pragma once
#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "TileMap.h"
#include "Player.h"
#include "BulletHandler.h"


class mainGame :
	public State
{
public:
	
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:

	TileMap* tileMap;
	Player* playerOne;
	BulletHandler* bulletHandler;
};

extern bool reset;

#endif