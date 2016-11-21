#include "TileMap.h"


TileMap::TileMap(std::string fileName)
{
	this->grassTexture = new sf::Texture();
	this->grassTexture->loadFromFile("resources/grass.png");

	this->stoneTexture = new sf::Texture();
	this->stoneTexture->loadFromFile("resources/stone.png");

	this->railTexture = new sf::Texture();
	this->railTexture->loadFromFile("resources/rail.png");

	this->woodTexture = new sf::Texture();
	this->woodTexture->loadFromFile("resources/wood.png");

	this->grassTile = new sf::Sprite(*this->grassTexture);

	this->stoneTile = new sf::Sprite(*this->stoneTexture);

	this->railTile = new sf::Sprite(*this->railTexture);
	this->railTile->rotate(90);

	this->woodTile = new sf::Sprite(*this->woodTexture);

	std::ifstream openFile(fileName);

	int rowCounter = 0, columnCounter = 0;

	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			char x;
			openFile >> x;

			if (isdigit(x))
			{
				this->map[rowCounter][columnCounter] = x - '0';
				rowCounter++;
			}

			if (openFile.peek() == '\n')
			{
				rowCounter = 0;
				columnCounter++;
			}	
		}
	}
}

void TileMap::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (this->map[i][j] == 0)
			{
				this->grassTile->setPosition(i * 32, j * 32);
				window->draw(*this->grassTile);
			}

			else if (this->map[i][j] == 1)
			{
				this->stoneTile->setPosition(i * 32, j * 32);
				window->draw(*this->stoneTile);
			}

			else if (this->map[i][j] == 2)
			{
				this->railTile->setPosition(i * 32, j * 32);
				this->grassTile->setPosition(i * 32, j * 32);
				window->draw(*this->grassTile);
				window->draw(*this->railTile);
			}

			else if (this->map[i][j] == 3)
			{
				this->woodTile->setPosition(i * 32, j * 32);
				window->draw(*this->woodTile);
			}
		}
	}
}

TileMap::~TileMap()
{
	delete this->grassTexture;
	delete this->stoneTexture;
	delete this->railTexture;

	delete this->stoneTile;
	delete this->grassTile;
	delete this->railTile;

	this->grassTexture = NULL;
	this->stoneTexture = NULL;
	this->railTexture = NULL;

	this->stoneTile = NULL;
	this->railTile = NULL;
	this->grassTile = NULL;
}

