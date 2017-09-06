#include "RangeWeapon.h"


RangeWeapon::RangeWeapon(BulletHandler* bulletHandler, sf::Vector2f position)
{
	this->setPosition(position);
	this->setBulletHandler(bulletHandler);
}

void RangeWeapon::Update()
{
	Weapon::Update(); 
}

void RangeWeapon::shot()
{
	this->calculateAim();
	this->bullet = new Bullet(this->getPosition(), this->getVelocity(), this->angle);
	this->bulletHandler->addBullet(bullet);
}

void RangeWeapon::calculateAim()
{
	sf::Vector2f tmp(sf::Mouse::getPosition().x, this->getPosition().y);

	float lengthA = std::abs(this->getPosition().x - tmp.x);
	float lengthB = std::abs(sf::Mouse::getPosition().y - tmp.y);
	float lengthC = std::sqrt(std::pow(lengthA, 2) + std::pow(lengthB, 2));

	double sinus = lengthB / lengthC;
	this->angle = std::asin(sinus) * (180 / M_PI);

	//1st square
	if (this->getPosition().x - tmp.x <= 0 && sf::Mouse::getPosition().y - tmp.y < 0)
	{
		this->velocity.x = 0.2f * (90 - this->angle);
		this->velocity.y = -0.2f * this->angle;
		this->angle = 90 - this->angle;
	}

	//2nd square
	else if (this->getPosition().x - tmp.x <= 0 && sf::Mouse::getPosition().y - tmp.y >= 0)
	{
		this->velocity.x = 0.2f * (90 - this->angle);
		this->velocity.y = 0.2f * this->angle;
		this->angle += 90;
	}

	//3th square
	else if (this->getPosition().x - tmp.x > 0 && sf::Mouse::getPosition().y - tmp.y >= 0)
	{
		this->velocity.x = -0.2f * (90 - this->angle);
		this->velocity.y = 0.2f * this->angle;
		this->angle = 270 - angle;
	}

	else if (this->getPosition().x - tmp.x > 0 && sf::Mouse::getPosition().y - tmp.y < 0)
	{
		this->velocity.x = -0.2f * (90 - this->angle);
		this->velocity.y = -0.2f * this->angle;
		this->angle += 270;
	}

	//std::cout << "velo x: " << this->velocity.x << " velo y: " << this->velocity.y << " angle: " << this->angle << " sinus: " << sinus << std::endl;
}

void RangeWeapon::setBulletHandler(BulletHandler* bulletHandler)
{
	this->bulletHandler = bulletHandler;
}

sf::Vector2f RangeWeapon::getVelocity()
{
	return this->velocity;
}

RangeWeapon::~RangeWeapon()
{
	this->bullet = NULL;
	this->bulletHandler = NULL;
}

