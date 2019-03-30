#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, kineticEnergy, velocity;
	sf::Vector2f lastRealPos, newRealPos, velocityVector, AirAccelerationVector{0.05,0.05};
	Physics *physics;

	sf::Vector2f calcRealVector(const sf::Vector2f &pixelVector);
	sf::Vector2f calcRealVector(const sf::Vector2i &pixelVector);
	sf::Vector2f calcPixelVector(const sf::Vector2f &realVector);
	float calcRealValue(const float &pixelValue);
	float calcPixelValue(const float &realValue);


	sf::Vector2f swapY(const sf::Vector2f &pos);

	sf::Vector2f calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &t);


	sf::Vector2f calcResistanceVector(sf::Vector2f VelocityVector, float resistance);


	float calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector);
	float calcKineticEnergy(const float &mass, const float &velocity);


public:
	PhysicalObject(Physics* physics, float mass, float posX, float posY, sf::Vector2f velocityVector);
	PhysicalObject(Physics* physics, float mass, float posX, float posY);
	virtual ~PhysicalObject();
};

