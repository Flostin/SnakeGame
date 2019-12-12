#include <SFML/Graphics.hpp>

#include "Powerup.h"
#include "Debug.h"

Powerup::Powerup(const char* filename) : SIZE(25) {
	this->texture = loadTexture(filename);
	this->sprite = sf::Sprite(this->texture);
	this->sprite.setScale(sf::Vector2f(this->texture.getSize()) / (float)SIZE);
}