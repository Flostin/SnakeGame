#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "Debug.h"
#include "Main.h"
#include "Apple.h"
#include "Snake.h"

Snake::Snake() : length(3), head(200, 200), direction(0, 0), SEGMENT_SIZE(25)
{
	segments.reserve(length);
	segments.push_back({ head.x, head.y });
}

void Snake::run(sf::RenderWindow* window)
{
	onInput();
	update();
	render(window);
}

void Snake::update()
{
	// Only updates the snake if it's moving
	if (direction.x != 0.0f || direction.y != 0.0f) {
		head += direction;

		if (segments.size() < length)
		{
			segments.push_back({ head.x, head.y });
		}
		else
		{
			// Moves the snake forawrd by taking the end of the snake and putting it in the front
			//sf::Vector2f temp = segments.at(0);
			segments.erase(segments.begin());
			segments.push_back({ head.x, head.y });
			std::cout << "Capacity: " << segments.capacity() << std::endl;
		}
	}
}

void Snake::render(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle;
	for (sf::Vector2f& segment : segments)
	{
		rectangle = sf::RectangleShape(sf::Vector2f((float)SEGMENT_SIZE, (float)SEGMENT_SIZE));
		rectangle.setFillColor(sf::Color::Green);
		rectangle.setPosition(segment);

		window->draw(rectangle);
	}
}

void Snake::onInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = -(float)SEGMENT_SIZE;
		direction.y = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = (float)SEGMENT_SIZE;
		direction.y = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.x = 0;
		direction.y = -(float)SEGMENT_SIZE;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.x = 0;
		direction.y = (float)SEGMENT_SIZE;
	}
}

bool Snake::checkWalls()
{
	std::cout << WIDTH << HEIGHT << std::endl;

	if (head.x <= -SEGMENT_SIZE || head.x >= WIDTH)
		return true;

	if (head.y <= -SEGMENT_SIZE || head.x >= HEIGHT)
		return true;

	return false;
}

bool Snake::checkApple(Apple& apple)
{
	if (head.x == apple.position.x && head.y == apple.position.y)
		return true;

	return false;
}

std::vector<sf::Vector2f>& Snake::getSegments() {
	return segments;
}

void Snake::addLength(int amt)
{
	length += amt;
};