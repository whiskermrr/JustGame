#pragma once
#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "EntityHandler.h"


class mainGame :
	public State
{
public:
	
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:

	EntityHandler* entityHandler;
};

extern bool reset;

#endif