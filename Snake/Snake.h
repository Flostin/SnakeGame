#pragma once

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
	void run(sf::RenderWindow& window);
	void update();
	void render(sf::RenderWindow& window);

	void onInput();
};

