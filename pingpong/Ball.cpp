#include "pch.h"
#include "Ball.h"

Ball::Ball(Physics* physics, float posX, float posY) : 
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, BALL_FRICTION, BALL_ELASTICITY, posX, posY) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * physics->viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));

	this->start_i = 0;
}

void Ball::applyGravity() {
	acc += {0, -physics->grav};
}

void Ball::applyAirResistance(const float &v, const sf::Vector2f &uV) {
	if (v != 0.0f) {
		acc += dragK * pow(v, 2) * uV;
	}
}

void Ball::applyForces() {
	applyGravity();
	applyAirResistance(velocity, unitVector);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const sf::Vector2f &acc, const float &t) {

	applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
}

void Ball::setPixelSize(const float &pR) {
	dObject->setRadius(pR);
	realRaidus = calcRealValue(pR);
}

void Ball::update()
{
	calcElapsedTime();
	acc = { 0.0f, 0.0f };

	if (start_i >= 3) {
		newRealPos = calcNewRealPos(lastRealPos, velocityVector, acc, elapsedTime);

		velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
		velocity = calcVelocityFromVelocityVector(velocityVector);
		unitVector = calcUnitVector(velocityVector, velocity);
		
	} else {
		start_i++;
	}

	dObject->setPosition(swapY(calcPixelVector(newRealPos)));
	lastRealPos = newRealPos;

	//Testy
	std::cout << "Ball velocity: " << velocity << " | Ball unit vector: [" << unitVector.x << "; " << unitVector.y << "]" << std::endl;
}

