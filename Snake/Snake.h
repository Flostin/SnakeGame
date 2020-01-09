#pragma once

class Apple;

class Snake
{
private:
	sf::Vector2f head;
	sf::Vector2f direction;

	std::vector<sf::Vector2f> segments;
	int length;

	const int SEGMENT_SIZE;
public:
	Snake();
	void run(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	void update();

	void onInput();
	// Has the snake gone out of bounds
	bool checkWalls();
	bool checkApple(Apple& apple);

	std::vector<sf::Vector2f>& getSegments();
	void addLength(int amt);
};