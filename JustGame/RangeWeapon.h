#pragma once
#ifndef RANGEWEAPON_H
#define RANGEWEAPON_H

#include "Weapon.h"
#include "BulletHandler.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846

class RangeWeapon :
	public Weapon
{
public:
	RangeWeapon(BulletHandler* bulletHandler, sf::Vector2f position);
	void setBulletHandler(BulletHandler* bulletHandler);
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();
	void Update();
	void calculateAim();
	void shot();
	~RangeWeapon();

public:

	Bullet* bullet;
	BulletHandler* bulletHandler;
	float angle;

private:
	sf::Vector2f velocity;
};

#endif

#endif

