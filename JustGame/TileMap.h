#pragma once
#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <ctype.h>
#include <string>
#include <fstream>

class TileMap
{
public:

	TileMap(std::string fileName);
	void Render(sf::RenderWindow* window);
	~TileMap();
	

private:
	sf::Texture* grassTexture;
	sf::Texture* stoneTexture;
	sf::Texture* railTexture;
	sf::Texture* woodTexture;

	sf::Sprite* grassTile;
	sf::Sprite* stoneTile;
	sf::Sprite* railTile;
	sf::Sprite* woodTile;

	int map[150][150];

};

#endif

