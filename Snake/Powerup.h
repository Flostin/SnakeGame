#pragma once

class Powerup
{
public:
	const int SIZE;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	Powerup(const char* filename, sf::Vector2f& position);
	virtual ~Powerup();

	void virtual render(sf::RenderWindow& window);
	void virtual onHit() = 0;
};

