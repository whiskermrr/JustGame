#pragma once
#include "state.h"
#include "Player.h"

class EntityHandler
{
public:

	EntityHandler(sf::RenderWindow* window);
	void Initiate();
	void Update();
	void Render();
	~EntityHandler();

private:

	sf::RenderWindow* window;

	Player* player;
	BulletHandler* bulletHandler;
	std::vector<Player*> *playerHandler; // maybe i will create class called PlayerHandler

	

};

