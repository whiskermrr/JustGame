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
			columnCounter = 0;

			if (isdigit(x))
			{
				this->map->push_back(new Tile(x - '0'));	
				columnCounter++;
			}

			if (openFile.peek() == '\n')
			{
				rowCounter++;
			}
		}
	}

	columnCounter = 44;

	std::cout << "Rows: " << rowCounter << " Columns: " << columnCounter << std::endl;
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
			this->map->at(i * columnCounter + j)->setPosition(j * 32, i * 32);
			window->draw(*this->map->at(i * columnCounter + j));
		}
	}
}

TileMap::~TileMap()
{
	for (std::vector<Tile*>::iterator it = this->map->begin(); it != this->map->end(); it++)
	{
		delete (*it);
	}

	delete this->map;
}

