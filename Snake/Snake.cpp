#include <vector>
#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Debug.h"

Snake::Snake() : length(3), head(200, 200), SEGMENT_SIZE(25)
{
	segments.push_back({ head.x, head.y });
	segments.push_back({ 342.0f, 542.0f });

	/*for (sf::Vector2f& segment : segments) {
		std::cout << segment << std::endl;
	}
	std::cout << sizeof(sf::Vector2f) << std::endl;*/

	std::vector<sf::Vector2f>* begin = &segments;
	std::cout << begin->at(0) << std::endl;
}

void Snake::run(sf::RenderWindow& window)
{
	//update();
	render(window);
}

void Snake::update()
{
	if (segments.size() < length)
	{
		segments.push_back({ head.x, head.y });
	}
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

}