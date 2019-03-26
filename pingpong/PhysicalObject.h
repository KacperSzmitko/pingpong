#pragma once

#include "Physics.h"

class PhysicalObject {
protected:

	float mass,shape,Ek,Ep,momentum;
	sf::Vector2f speed,acceleration;
	Physics *physics;
	sf::Time last_clock;


	sf::Time timeDiffrence();
	
	
public:
	PhysicalObject(float mass,Physics *physics);
	// float calculate_speed(float direction, float road, Physics *phy, float time);
	virtual ~PhysicalObject();
};

