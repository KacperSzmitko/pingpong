#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"
#define PI 3.14159265

class Ball : public UpdateObject, public PhysicalObject, public DrawnObject<sf::CircleShape>
{
private:
	float Vp, Vx_p, Vy_p,r,angle;
	sf::Vector2f ActualPosition;
	float Vx, Vy;
	

public:
	Ball(float r, float posX, float posY, float mass, Physics* physics, float Vp);
	void update();
	

};


