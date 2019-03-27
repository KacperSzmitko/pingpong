#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, kineticEnergy, realSpeed;
	sf::Vector2f realSpeedVector;
	Physics *physics;

	sf::Vector2f calcRealSpeedVector(sf::Vector2f lastPixelPos, sf::Vector2f newPixelPos, float &t);
	float calcRealSpeedFromRealSpeedVector(sf::Vector2f &realSpeedVector);

public:
	PhysicalObject(float mass, sf::Vector2f realSpeedVector, Physics* physics);
	virtual ~PhysicalObject();
};

