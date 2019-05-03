#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"

class Rect : public DrawnObject<sf::RectangleShape>, public PhysicalObject {

	friend class Collision;

protected:
	float realLength, realWidth, angle;


public:
	Rect(float pixelSizeX, float pixelSizeY, float angle, float friction, float elasticity, float pixelPosX, float pixelPosY);
	virtual ~Rect();
};

