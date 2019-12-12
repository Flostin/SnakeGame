#pragma once
#include "Powerup.h"

class Apple : public Powerup
{
public:
	Apple(const char* filename, sf::Vector2f position);
	void onHit() override;
};

