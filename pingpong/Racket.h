#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Racket : public UpdateObject, public DrawnObject<sf::RectangleShape>, public PhysicalObject {
private:
	sf::Vector2i lastPos;
	sf::Vector2i newPos;

	sf::Vector2f intVectorToFloatVector(const sf::Vector2i &vec);

public:
	Racket(float sizeX, float sizeY, int posX, int posY, float mass, Physics * physics);

	void update();

	~Racket();
};

