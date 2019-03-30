#include "pch.h"
#include "Ball.h"

Ball::Ball(Physics *physics, float r, float mass, float posX, float posY) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(physics, mass, posX, posY) {
	this->realRaidus = calcRealValue(r);
	this->dObject->setPosition(swapY({ posX, posY }));
}

Ball::Ball(Physics* physics, float posX, float posY) : 
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(swapY({ posX, posY }));
}

Ball::Ball(Physics *physics, float posX, float posY, sf::Vector2f velocityVector) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY, velocityVector) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(swapY({ posX, posY }));
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const float &t) {

	sf::Vector2f nV(lV);
	float a = physics->grav;

	nV.x += vV.x * t;
	nV.y += (2.0f * vV.y - a * t) * t * 0.5f;

	return nV;
}

void Ball::update()
{
	calcElapsedTime();

	newRealPos = calcNewRealPos(lastRealPos, velocityVector, elapsedTime);
	
	dObject->setPosition(swapY(calcPixelVector(newRealPos)));


	velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
	lastRealPos = newRealPos;
}

