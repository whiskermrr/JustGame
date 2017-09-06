#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "RangeWeapon.h"

enum Direction { UP, LEFT, DOWN, RIGHT };

class Player : public Creature
{
public:
	Player(BulletHandler* bulletHandler);
	void Update();
	void Render(sf::RenderWindow* window);
	~Player();

public:
	BulletHandler* bulletHandler;
	RangeWeapon* rangeWeapon;
};

#endif