#pragma once

#include "UpdateObject.h"
#include "SimObject.h"

class MovingObject : public UpdateObject, public SimObject {
protected:

	float mass, velocity, kineticEnergy;
	sf::Vector2f oldRealPos, velocityVector, unitVector;

	sf::Vector2f calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &t);
	float calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector);
	sf::Vector2f calcUnitVector(const sf::Vector2f &velocityVector, const float &velocity);
	float calcKineticEnergy(const float &mass, const float &velocity);

public:

	MovingObject(float mass);

	void setMass(const float &mass);
	void setVelocityVector(const sf::Vector2f &velocityVector);
	void setOldRealPos(const sf::Vector2f &oRP);
};

