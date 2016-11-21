#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:

	Entity();
	void LoadTexture(std::string file);
	void Update();
	bool CheckCollision(Entity* gameObject);
	~Entity();

private:

	sf::Texture* texture;

public:

	sf::Vector2f velocity;

};

#endif