#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass, Ek, Ep, momentum;
	sf::Vector2f speed, acceleration;
	Physics * physics;

public:
	PhysicalObject(float mass, Physics* physics);
	// float calculate_speed(float direction, float road, Physics *phy, float time);
	virtual ~PhysicalObject();
};

