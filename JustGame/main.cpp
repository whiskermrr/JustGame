#include "gameState.h"

gameState mainState;
bool gameExit = false;
sf::Vector2f screenDimensions(1366, 768);

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "mrr");

	window.setFramerateLimit(120);

	mainState.setWindow(&window);
	mainState.setState(new mainGame());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		mainState.Update();
		mainState.Render();

		window.display();

		if (gameExit)
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}