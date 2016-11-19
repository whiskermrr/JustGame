#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "RangeWeapon.h"

enum Direction { UP, LEFT, DOWN, RIGHT };

class Player : public Entity
{
public:
	Player(BulletHandler* bulletHandler);
	void Update();
	void Render(sf::RenderWindow* window);
	~Player();

public:
	sf::Vector2i source;
	BulletHandler* bulletHandler;
	RangeWeapon* rangeWeapon;

};

#endif