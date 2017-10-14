#pragma once
#include "Entity.h"
#include "CreatureAttributes.h"
#include "Tile.h"

#define PLAYER_SPEED 2
#define PLAYER_KNOCK 4
#define PLAYER_START_HIT_POINTS 100

class Creature :
	public Entity
{
public:
	Creature();
	void Update();
	sf::Vector2i getSource();
	CreatureAttributes getAttributes();
	void takeDamage(int damage);
	void setHitPoints(int hitPoints);
	int getHitPoints();
	void setArmor(int armor);
	int getArmor();
	void checkCollisionWithWall();
	void setTiles(std::vector<Tile*> *tiles);
	~Creature();

public:

	sf::Vector2i source;
	CreatureAttributes creatureAttributes;
	std::vector<Tile*> *tiles;
	bool isDead;
	float right;
	float left;
	float top;
	float bottom;
};

