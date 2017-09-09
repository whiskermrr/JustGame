#include "Creature.h"



Creature::Creature()
{
	this->setHitPoints(100);
	this->setArmor(0);
	this->isDead = false;
	_canMoveUp = true;
	_canMoveDown = true;
	_canMoveRight = true;
	_canMoveLeft = true;
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

bool Creature::canMoveUp()
{
	return _canMoveUp;
}

bool Creature::canMoveDown()
{
	return _canMoveDown;
}

bool Creature::canMoveRight()
{
	return _canMoveRight;
}

bool Creature::canMoveLeft()
{
	return _canMoveLeft;
}

void Creature::setMoveUp(bool canMove)
{
	_canMoveUp = canMove;
}

void Creature::setMoveDown(bool canMove)
{
	_canMoveDown = canMove;
}

void Creature::setMoveRight(bool canMove)
{
	_canMoveRight = canMove;
}

void Creature::setMoveLeft(bool canMove)
{
	_canMoveLeft = canMove;
}

// TODO make better collision system with wall

bool Creature::checkCollisionWithWall(Tile* tile)
{
	return this->getGlobalBounds().intersects(tile->getGlobalBounds());
}


Creature::~Creature()
{
}
