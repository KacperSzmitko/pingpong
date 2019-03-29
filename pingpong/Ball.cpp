#include "pch.h"
#include "Ball.h"

Ball::Ball(float r, float posX, float posY, float mass, Physics *physics) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(physics, mass, posX, posY) {
	this->realRaidus = calcRealValue(r);
	this->dObject->setPosition(posX, posY);
}

Ball::Ball(Physics* physics, float posX, float posY) : 
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(posX, posY);
}
void Ball::update()
{
	dObject->move(0.1f, 0.1f);
}

float Ball::CalculateVx()
{
	return 0;
};

float Ball::CalculateVy()
{
	return 0;
};

void Ball::calculateHmax()
{
	Hmax = pow(Vx/100, 2) / (2 * physics->grav);
}


void Ball::CalculateSx() {};


