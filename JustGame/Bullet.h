#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "Tile.h"
#include <iostream>

class Bullet : public Entity
{
public:
	Bullet(sf::Vector2f position, sf::Vector2f velocity, float angle);
	void Update();
	bool checkCollisionWithWall(Tile* tile);
	~Bullet();

private:
};

#endif

