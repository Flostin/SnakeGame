#pragma once

class Powerup
{
public:
	const int SIZE;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	Powerup(const char* filename);
	//virtual
};

