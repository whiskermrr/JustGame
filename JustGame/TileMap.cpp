#include "TileMap.h"


TileMap::TileMap(std::string fileName)
{
	std::ifstream openFile(fileName);

	this->map = new std::vector<Tile*>();

	this->rowCounter = 0, this->columnCounter = 0;

	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			char x;
			openFile >> x;

			if (isdigit(x))
			{
				Tile* tile = new Tile(x - '0');
				tile->setPosition(columnCounter * 32, rowCounter * 32);
				this->map->push_back(tile);
				columnCounter++;
			}

			if (openFile.peek() == '\n')
			{
				rowCounter++;
				columnCounter = 0;
			}
		}
	}
}

std::vector<Tile*>* TileMap::getTiles()
{
	return this->map;
}

void TileMap::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < this->rowCounter; i++)
	{
		for (int j = 0; j < this->columnCounter; j++)
		{
			//this->map->at(i * columnCounter + j)->setPosition(j * 32, i * 32);
			window->draw(*this->map->at(i * columnCounter + j));
		}
	}
}

int TileMap::getRows()
{
	return this->rowCounter;
}

int TileMap::getColumns()
{
	return this->columnCounter;
}

TileMap::~TileMap()
{
	for (std::vector<Tile*>::iterator it = this->map->begin(); it != this->map->end(); it++)
	{
		delete (*it);
	}

	delete this->map;
}

