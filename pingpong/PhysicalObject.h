#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, kineticEnergy, velocity;
	sf::Vector2f lastRealPos, newRealPos, velocityVector;
	Physics *physics;

	sf::Vector2f calcRealPos(const sf::Vector2f &pixelPos);
	sf::Vector2f calcRealPos(const sf::Vector2i &pixelPos);
	sf::Vector2f calcPixelPos(const sf::Vector2f &realPos);

	sf::Vector2f calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &t);
	float calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector);
	float calcKineticEnergy(const float &mass, const float &velocity);

public:
	PhysicalObject(Physics* physics, float posX, float posY, float mass, sf::Vector2f velocityVector);
	PhysicalObject(Physics* physics, float posX, float posY, float mass);
	virtual ~PhysicalObject();
};

