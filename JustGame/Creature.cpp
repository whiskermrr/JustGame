#include "Creature.h"



Creature::Creature()
{
	this->setHitPoints(100);
	this->setArmor(0);
	this->isDead = false;
	this->_canMove = true;
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

bool Creature::canMove()
{
	return _canMove;
}

void Creature::setMove(bool canMove)
{
	this->_canMove = canMove;
}

// TODO make better collision system with wall

bool Creature::checkCollisionWithWall(Tile* tile)
{
	return this->getGlobalBounds().intersects(tile->getGlobalBounds());
}


Creature::~Creature()
{
}
