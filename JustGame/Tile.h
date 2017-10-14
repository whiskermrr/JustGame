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
	void setBorders();
	~Tile();

private:

	bool _isWall;
	TileType tileType;

public:
	float right;
	float left;
	float top;
	float bottom;
};

