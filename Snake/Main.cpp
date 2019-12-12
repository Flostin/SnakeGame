/*
 * TODO:
 * Add powerups (apple, bomb, and power star)
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "Snake.h"

#define WIDTH 800
#define HEIGHT 800

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game!");
	Snake snake;

	bool gameOver = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		snake.run(window);
		window.display();
	}

	return 0;
}