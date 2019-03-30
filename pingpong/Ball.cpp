#include "pch.h"
#include "Ball.h"

Ball::Ball(Physics *physics, float r, float mass, float posX, float posY) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(physics, mass, posX, posY) {
	this->realRaidus = calcRealValue(r);
	this->crossSectionArea = PI * pow(realRaidus, 2);
	this->drag = BALL_DEFAULT_DRAG;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));
}

Ball::Ball(Physics* physics, float posX, float posY) : 
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->crossSectionArea = 2.0f * PI * pow(realRaidus, 2);
	this->drag = BALL_DEFAULT_DRAG;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));
}

Ball::Ball(Physics *physics, float posX, float posY, sf::Vector2f velocityVector) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY, velocityVector) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->crossSectionArea = 2.0f * PI * pow(realRaidus, 2);
	this->drag = BALL_DEFAULT_DRAG;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));
}

void Ball::applyGravity() {
	acc += {0, -physics->grav};
}

void Ball::applyAirResistance(const sf::Vector2f &vV, const float &v) {
	if (v != 0.0f) {
		sf::Vector2f unitVector = vV / v;
		acc += (-0.5f * physics->viscosity * pow(v, 2) * crossSectionArea * drag * unitVector) / mass;
	}
}

void Ball::applyForces() {
	applyGravity();
	applyAirResistance(velocityVector, velocity);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const sf::Vector2f &acc, const float &t) {

	applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
}

void Ball::update()
{
	calcElapsedTime();

	newRealPos = calcNewRealPos(lastRealPos, velocityVector, acc, elapsedTime);

	dObject->setPosition(swapY(calcPixelVector(newRealPos)));
	velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
	velocity = calcVelocityFromVelocityVector(velocityVector);	

	std::cout << elapsedTime << " " << velocityVector.x << " " << velocityVector.y << std::endl;
	lastRealPos = newRealPos;
	acc = { 0.0f, 0.0f };

}

