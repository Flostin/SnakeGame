#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

std::ostream& operator<<(std::ostream& stream, sf::Vector2f& vector);
sf::Texture loadTexture(const char* filename);