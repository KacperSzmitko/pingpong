#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"

class Rect : public DrawnObject<sf::RectangleShape>, public PhysicalObject {

	friend class Collision;

protected:
	float realLength, realWidth, angle, pixelRadius;
	sf::Vector2f localSP, localEP;

public:
	Rect(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY);
	virtual ~Rect();
};

