#include <SFML/Graphics.hpp>
#include "Debug.h"
#include "Main.h"
#include "Powerup.h"
#include "Snake.h"
#include "Apple.h"
#include "Game.h"

Game::Game() : scene(SCENE::GAME), apple(sf::Vector2f(-20, -20))
{
	clock.restart();
}

void Game::run()
{
	window->clear();

	switch (scene)
	{
	case SCENE::MENU:
		runMenu();
		break;
	case SCENE::GAME:
		runGame();
		break;
	case SCENE::OVER:
		runGameOver();
		break;
	}

	window->display();
}

void Game::runMenu()
{
	
}

void Game::runGame()
{
	snake.run(window);
	apple.render(window);

	if (snake.checkApple(apple))
		apple.onHit(snake);
}

void Game::runGameOver()
{

}

void Game::update()
{
	if (clock.getElapsedTime().asMilliseconds() > 100)
	{
		run();
		clock.restart();
	}
}