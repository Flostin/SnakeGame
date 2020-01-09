#include <SFML/Graphics.hpp>
#include "Powerup.h"
#include "Snake.h"
#include "Apple.h"

Apple::Apple(sf::Vector2f position)
	: Powerup("Apple.png", position)
{
	
}

void Apple::onHit(Snake& snake)
{
	snake.getSegments().reserve(2);
	snake.addLength(2);
}