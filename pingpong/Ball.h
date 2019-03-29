#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

#define BALL_DEFAULT_PIXEL_RADIUS 4.0f
#define BALL_DEFAULT_MASS 0.0025f

class Ball : public UpdateObject, public PhysicalObject, public DrawnObject<sf::CircleShape>
{
private:
	float realRaidus;
	float Hmax = 0,Vx,Vy;

public:
	Ball(float realRaidus, float posX, float posY, float mass, Physics* physics);
	Ball(Physics* physics, float posX, float posY);
	void update();
	void CalculateSx();
	void CalculateSy();
	float CalculateVx();
	float CalculateVy();
	void CalculateA();
	void calculateHmax();

};


