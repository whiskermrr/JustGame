#pragma once
#ifndef TILE_H
#define TILE_H


#include <SFML/Graphics.hpp>

class BaseEntity : public sf::Sprite
{
public:

	BaseEntity();
	void LoadTexture(std::string file);
	~BaseEntity();

public:

	sf::Texture* texture;
};

#endif

