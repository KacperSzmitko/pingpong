#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Ball : public UpdateObject,public PhysicalObject,public DrawnObject<sf::CircleShape>
{
private:
	double r;

public:
	Ball();
};


