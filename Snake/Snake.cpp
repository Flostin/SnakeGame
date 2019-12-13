#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Debug.h"

Snake::Snake() : length(3), head(200, 200), direction(0, 0), SEGMENT_SIZE(25)
{
	segments.reserve(length);
	segments.push_back({ head.x, head.y });
}

void Snake::run(sf::RenderWindow& window)
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

	//std::cout << segments.size() * sizeof(sf::Vector2f) << std::endl;
}

void Snake::render(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle;
	for (sf::Vector2f& segment : segments)
	{
		rectangle = sf::RectangleShape(sf::Vector2f((float)SEGMENT_SIZE, (float)SEGMENT_SIZE));
		rectangle.setFillColor(sf::Color::Green);
		rectangle.setPosition(segment);

		window.draw(rectangle);
	}
}

void Snake::onInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = -SEGMENT_SIZE;
		direction.y = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = SEGMENT_SIZE;
		direction.y = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.x = 0;
		direction.y = -SEGMENT_SIZE;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.x = 0;
		direction.y = SEGMENT_SIZE;
	}
}