#include "Tile.h"
#include <iostream>

Tile::Tile(int tileType)
{
	switch (tileType)
	{
	case 0:
		this->tileType = SPACE;
		this->LoadTexture("space.png");
		this->_isWall = false;
		break;

	case 1:
		this->tileType = GRASS;
		this->LoadTexture("grass.png");
		this->_isWall = false;
		break;

	case 2:
		this->tileType = STONE;
		this->LoadTexture("stone.png");
		this->_isWall = true;
		break;

	case 3:
		this->tileType = RAIL;
		this->LoadTexture("rail.png");
		this->_isWall = false;
		break;

	case 4:
		this->tileType = WOOD;
		this->LoadTexture("wood.png");
		this->_isWall = false;
		break;

	case 5:
		this->tileType = WALL_BRICK;
		this->LoadTexture("wall_brick.png");
		this->_isWall = true;
		break;

	case 6:
		this->tileType = NETHER;
		this->LoadTexture("nether.png");
		this->_isWall = false;
		break;

	default:
		this->tileType = GRASS;
		this->LoadTexture("grass.png");
		this->_isWall = false;
		break;
	}
}

bool Tile::isWall()
{
	return this->_isWall;
}

void Tile::setIsWall(bool isItWall)
{
	this->_isWall = isItWall;
}

TileType Tile::getTileType()
{
	return this->tileType;
}


Tile::~Tile()
{
}
