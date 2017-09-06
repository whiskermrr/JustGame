#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "BaseEntity.h"
#include <string>

class Entity : public BaseEntity
{
public:

	Entity();
	void Update();
	bool CheckCollision(BaseEntity* gameObject);
	~Entity();

public:

	sf::Vector2f velocity;

};

#endif