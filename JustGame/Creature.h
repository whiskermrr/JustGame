#pragma once
#include "Entity.h"
#include "CreatureAttributes.h"
#include "Tile.h"

class Creature :
	public Entity
{
public:
	Creature();
	sf::Vector2i getSource();
	CreatureAttributes getAttributes();
	void takeDamage(int damage);
	void setHitPoints(int hitPoints);
	int getHitPoints();
	void setArmor(int armor);
	int getArmor();
	bool canMove();
	bool checkCollisionWithWall(Tile* tile);
	void setMove(bool canMove);
	~Creature();

public:

	sf::Vector2i source;
	CreatureAttributes creatureAttributes;
	bool isDead;
	bool _canMove;
};

