#include "Debug.h"

std::ostream& operator<<(std::ostream& stream, sf::Vector2f& vector)
{
	stream << "(" << vector.x << ", " << vector.y << ")";
	return stream;
}

sf::Texture loadTexture(const char* filename)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filename)) {
		std::cout << "File '" << filename << "' was not found!" << std::endl;
	}

	return texture;
}