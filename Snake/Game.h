#pragma once

class Game
{
public:
	// Game objects
	sf::Clock clock;
	Apple apple;
	Snake snake;

	// Game scene
	enum class SCENE
	{
		MENU, GAME, OVER
	};

	SCENE scene;

	Game();

	// Game scenes
	void run();
	void runMenu();
	void runGame();
	void runGameOver();

	void update();
};