#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Ball : public UpdateObject, public PhysicalObject, public DrawnObject<sf::CircleShape>
{
private:
	float r;
	float Hmax = 0,Vx,Vy;

public:
	Ball(float r, float posX, float posY, float mass, Physics* physics);
	void update();
	void CalculateSx();
	void CalculateSy();
	float CalculateVx();
	float CalculateVy();
	void CalculateA();
	void calculateHmax();

};


