#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"

class Racket : private DrawnObject<sf::RectangleShape>, private PhysicalObject {
public:
	Racket(float sizeX, float sizeY, float posX, float posY);

	void update();

	~Racket();
};

