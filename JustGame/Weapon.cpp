#include "Weapon.h"


Weapon::Weapon() 
{
	this->texture = new sf::Texture();
}

void Weapon::loadTexture(std::string fileName)
{
	this->texture->loadFromFile("resources/" + fileName);
	this->setTexture(*this->texture);
}

void Weapon::Update()
{

}

void Weapon::setDamage(double damage)
{
	this->damage = damage;
}

double Weapon::getDamage()
{
	return this->damage;
}

Weapon::~Weapon()
{
	delete this->texture;
	this->texture = NULL;
}
