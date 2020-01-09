/*
 * TODO:
 * Add powerups (apple, bomb, and power star)
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "Main.h"
#include "Game.h"

const int WIDTH = 800;
const int HEIGHT = 800;
sf::RenderWindow* window;

int main()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Snake Game!");
	Game game;

	while (window->isOpen()) 
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			}
		}

		game.update();
	}

	delete window;

	return 0;
}