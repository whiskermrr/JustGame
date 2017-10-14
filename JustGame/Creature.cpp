#include "Creature.h"



Creature::Creature()
{
	this->setHitPoints(PLAYER_START_HIT_POINTS);
	this->setArmor(0);
	this->isDead = false;
}

void Creature::Update()
{
	top = this->getPosition().y;
	bottom = this->getPosition().y + this->getTextureRect().height;
	left = this->getPosition().x;
	right = this->getPosition().y + this->getTextureRect().width;
}

sf::Vector2i Creature::getSource()
{
	return this->source;
}

CreatureAttributes Creature::getAttributes()
{
	return this->creatureAttributes;
}

void Creature::takeDamage(int damage)
{
	int taken = damage - ( 0.1 * getArmor() );
	
}

void Creature::setHitPoints(int hitPoints)
{
	creatureAttributes.hitPoints = hitPoints;
}

int Creature::getHitPoints()
{
	return creatureAttributes.hitPoints;
}

void Creature::setArmor(int armor)
{
	creatureAttributes.armor = armor;
}

int Creature::getArmor()
{
	return creatureAttributes.armor;
}

void Creature::checkCollisionWithWall()
{

	float playerX = this->getPosition().x;
	float playerY = this->getPosition().y;

	for (int i = 0; i != this->tiles->size(); i++)
	{
		if (this->tiles->at(i)->isWall() && this->CheckCollision(this->tiles->at(i)))
		{
			if (i == 0)
			{
				if (this->top < this->tiles->at(0)->bottom - PLAYER_SPEED)
					playerX = playerX + PLAYER_KNOCK;
				else
					playerY = playerY + PLAYER_KNOCK;
			}
			else if (i == 1)
			{
				if (this->top < this->tiles->at(1)->bottom - PLAYER_SPEED)
					playerX = playerX - PLAYER_KNOCK;
				else
					playerY = playerY + PLAYER_KNOCK;
			}

			else if (i == 2)
				playerX = playerX + PLAYER_KNOCK;

			else if (i == 3)
				playerX = playerX - PLAYER_KNOCK;

			else if (i == 4)
				playerY = playerY - PLAYER_KNOCK;

			else if (i == 5)
				playerY = playerY - PLAYER_KNOCK;

			this->setPosition(playerX, playerY);
		}
	}
}

void Creature::setTiles(std::vector<Tile*> *tiles)
{
	this->tiles = tiles;
}


Creature::~Creature()
{
}
