#include <SFML/Graphics.hpp>

#include "Debug.h"
#include "Snake.h"
#include "Powerup.h"

Powerup::Powerup(const char* filename, sf::Vector2f& position) : SIZE(25) {
	texture = loadTexture(filename);
	sprite = sf::Sprite(texture);

	sf::Vector2f textureSize = sf::Vector2f(texture.getSize());
	sprite.setScale(sf::Vector2f((float)SIZE / textureSize.x, (float)SIZE / textureSize.y));

	sprite.setPosition(position);
}

Powerup::~Powerup()
{
	std::cout << "The instance has been destroyed!" << std::endl;
}

void Powerup::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}