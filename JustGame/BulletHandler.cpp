#include "BulletHandler.h"
#include <iostream>


BulletHandler::BulletHandler()
{
	this->bulletVector = new std::vector<Bullet*>();
}

void BulletHandler::Update()
{
	std::for_each(this->bulletVector->begin(), this->bulletVector->end(), [](Bullet* it) {it->Update(); });

	for (std::vector<Bullet*>::iterator it = this->bulletVector->begin(); it != this->bulletVector->end();)
	{
		if ((*it)->getPosition().x > 1366 || (*it)->getPosition().y > 768 || (*it)->getPosition().x < 0 || (*it)->getPosition().y < 0)
		{
			delete *it;
			it = this->bulletVector->erase(it);
		}

		else
			it++;
	}
}

void BulletHandler::Render(sf::RenderWindow* window)
{
	std::for_each(this->bulletVector->begin(), this->bulletVector->end(), [&window](Bullet* it) { window->draw(*it); });
}

BulletHandler::~BulletHandler()
{
	for (std::vector<Bullet*>::iterator it = this->bulletVector->begin(); it != this->bulletVector->end(); it++)
	{
		delete (*it);
	}

	this->bulletVector->clear();
	delete this->bulletVector;
}

void BulletHandler::addBullet(Bullet* bullet)
{
	this->bulletVector->push_back(bullet);
}
