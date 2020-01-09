#pragma once

class Apple : public Powerup
{
public:
	sf::Vector2f position;

	Apple(sf::Vector2f position);
	void onHit(Snake& snake) override;
};