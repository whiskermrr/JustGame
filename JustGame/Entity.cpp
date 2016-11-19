#include "Entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->velocity = sf::Vector2f(0, 0);
}

void Entity::LoadTexture(std::string file)
{
	this->texture->loadFromFile("resources/" + file);
	this->setTexture(*this->texture);
}

void Entity::Update()
{
	this->move(this->velocity);
}

bool Entity::CheckCollision(Entity* gameObject)
{
	return this->getGlobalBounds().intersects(gameObject->getGlobalBounds());
}

void Entity::Destroy()
{
	delete this->texture;
}