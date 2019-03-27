#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, kineticEnergy, speed;
	sf::Vector2f speedVector;
	Physics *physics;

	sf::Vector2f calcSpeedVector(sf::Vector2f lastPos, sf::Vector2f newPos, float &t);
	float calcSpeedFromSpeedVector(sf::Vector2f &speedVector);

public:
	PhysicalObject(float mass, sf::Vector2f vectorSpeed, Physics* physics);
	virtual ~PhysicalObject();
};

