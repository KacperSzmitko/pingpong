#include "pch.h"
#include "Ball.h"
#include "CountingFunctions.h"

Ball::Ball(Physics *physics, float r, float mass, float posX, float posY) :
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

Ball::Ball(Physics *physics, float posX, float posY, sf::Vector2f velocityVector) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY, velocityVector) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(posX, posY);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lastRealPos, const sf::Vector2f &velocityVector, const float &time) {
	return { lastRealPos.x + (velocityVector.x * time), lastRealPos.y + (2.0f * velocityVector.y - physics->grav * time) * time * 0.5f };
}

void Ball::update()
{
	calcElapsedTime();

	newRealPos = calcNewRealPos(lastRealPos, velocityVector, elapsedTime);
	
	dObject->setPosition(swapY(calcPixelVector(newRealPos)));

	velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
	lastRealPos = newRealPos;
}

