#pragma once
#include "BaseEntity.h"

enum TileType
{
	GRASS, STONE, RAIL, WOOD, SPACE, WALL_BRICK, NETHER
};

class Tile :
	public BaseEntity
{
public:
	Tile(int tileType);
	bool isWall();
	void setIsWall(bool isItWall);
	TileType getTileType();
	~Tile();

private:

	bool _isWall;
	TileType tileType;
};

