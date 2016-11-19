#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>


class Weapon :
	public sf::Sprite
{
public:
	Weapon();
	void loadTexture(std::string fileName);
	void Update();
	void setDamage(double damage);
	double getDamage();
	~Weapon();


private:
	sf::Texture* texture;
	double damage;
	sf::Vector2f position;

public:
};

#endif

