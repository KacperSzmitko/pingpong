#pragma once

class PhysicalObject {
protected:

	float friction, elasticity;
	sf::Vector2f realPos;

public:
	PhysicalObject(float friction, float elasticity, float pixelPosX, float pixelPosY);
};

