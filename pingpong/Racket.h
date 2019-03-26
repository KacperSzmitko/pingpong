#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Racket : public UpdateObject, public DrawnObject<sf::RectangleShape>, public PhysicalObject {

	

public:
	Racket(float sizeX, float sizeY, float posX, float posY,float mass, Physics* physics);

	void update();

	~Racket();
};

