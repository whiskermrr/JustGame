#include "Bullet.h"


Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float angle)
{
	this->LoadTexture("bullet.png");
	this->setPosition(position);
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	this->rotate(angle);
}

void Bullet::Update()
{
	Entity::Update();
}

bool Bullet::checkCollisionWithWall(Tile* tile)
{
	return this->getGlobalBounds().intersects(tile->getGlobalBounds());
}


Bullet::~Bullet()
{
	Entity::~Entity();
}
