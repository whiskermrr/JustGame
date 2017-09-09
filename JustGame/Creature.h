#pragma once
#include "Entity.h"
#include "CreatureAttributes.h"
#include "Tile.h"

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
	bool canMoveUp();
	bool canMoveDown();
	bool canMoveRight();
	bool canMoveLeft();
	void setMoveLeft(bool canMove);
	void setMoveRight(bool canMove);
	void setMoveUp(bool canMove);
	void setMoveDown(bool canMove);
	bool checkCollisionWithWall(Tile* tile);
	~Creature();

public:

	sf::Vector2i source;
	CreatureAttributes creatureAttributes;
	bool isDead;
	bool _canMoveUp;
	bool _canMoveDown;
	bool _canMoveRight;
	bool _canMoveLeft;
	float right;
	float left;
	float top;
	float bottom;
};

