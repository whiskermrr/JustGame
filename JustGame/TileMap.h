#pragma once
#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <ctype.h>
#include <string>
#include <fstream>
#include <vector>
#include "Tile.h"
#include <iostream>

class TileMap
{
public:

	TileMap(std::string fileName);
	void Render(sf::RenderWindow* window);
	std::vector<Tile*>* getTiles();
	~TileMap();
	

private:

	int rowCounter;
	int columnCounter;
	std::vector<Tile*> *map;
};

#endif

