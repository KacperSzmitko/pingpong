#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, friction, elasticity, kineticEnergy, velocity;
	sf::Vector2f lastRealPos, newRealPos, velocityVector, unitVector;
	Physics *physics;

	sf::Vector2f calcRealVector(const sf::Vector2f &pixelVector);
	sf::Vector2f calcRealVector(const sf::Vector2i &pixelVector);
	sf::Vector2f calcPixelVector(const sf::Vector2f &realVector);
	float calcRealValue(const float &pixelValue);
	float calcPixelValue(const float &realValue);

	sf::Vector2f swapY(const sf::Vector2f &pos);

	sf::Vector2f calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &t);
	float calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector);
	sf::Vector2f calcUnitVector(const sf::Vector2f &velocityVector, const float &velocity);
	float calcKineticEnergy(const float &mass, const float &velocity);

public:
	PhysicalObject(Physics* physics, float mass, float friction, float elasticity, float posX, float posY);

	void setMass(const float &mass);
	void setVelocityVector(const sf::Vector2f &velocityVector);
	void setRealPos(const sf::Vector2f &realPos);

	virtual ~PhysicalObject();
};

