#pragma once

#include "Physics.h"

class PhysicalObject {

protected:
	Physics::Material material;
	sf::Vector2f realPos;

public:
	PhysicalObject(Physics::Material material, float pixelPosX, float pixelPosY);
};

