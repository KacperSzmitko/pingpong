#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Racket : private UpdateObject, private DrawnObject<sf::RectangleShape>, private PhysicalObject {
public:
	Racket(float sizeX, float sizeY, float posX, float posY);

	void update();

	~Racket();
};

