#include "Entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->velocity = sf::Vector2f(0, 0);
}

void Entity::Update()
{
	this->move(this->velocity);
}

bool Entity::CheckCollision(BaseEntity* gameObject)
{
	return this->getGlobalBounds().intersects(gameObject->getGlobalBounds());
}

Entity::~Entity()
{
	delete this->texture;
	this->texture = NULL;
}