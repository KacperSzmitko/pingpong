#include "pch.h"
#include "Ball.h"

Ball::Ball(float r, float posX, float posY, float mass, Physics *physics) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(mass, sf::Vector2f(0, 0), physics),
	r(r)
{
	dObject->setPosition(posX, posY);
}
void Ball::update()
{
	dObject->move(0.01f, 0.01f);
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


