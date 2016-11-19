#pragma once
#ifndef BULLETHANDLER_H
#define BULLETHANDLER_H

#include "Bullet.h"
#include <vector>
#include <algorithm>
#include "state.h"

class BulletHandler
{
public:

	BulletHandler();
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
	void addBullet(Bullet* bullet);

private:

	std::vector<Bullet*> *bulletVector;
};

#endif

