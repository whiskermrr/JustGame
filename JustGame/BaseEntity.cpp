#include "BaseEntity.h"



BaseEntity::BaseEntity()
{
	this->texture = new sf::Texture();
}

void BaseEntity::LoadTexture(std::string file)
{
	this->texture->loadFromFile("resources/" + file);
	this->setTexture(*this->texture);
}


BaseEntity::~BaseEntity()
{
}
