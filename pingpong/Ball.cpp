#include "pch.h"
#include "Ball.h"
#include "Game.h"

Ball::Ball(Physics* physics, float posX, float posY) : 
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(Physics::Materials::wood, posX, posY),
	MovingObject(BALL_DEFAULT_MASS) {
	this->physics = physics;
	this->pixelRaidus = BALL_DEFAULT_PIXEL_RADIUS;
	this->realRaidus = Physics::calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * physics->viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setOrigin(BALL_DEFAULT_PIXEL_RADIUS, BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(Physics::swapY({ posX, posY }));
	isballmove = true;
	Collision::getBallCollisionVector()._add(this);
}
   
void Ball::applyGravity() {
	acc += {0, -physics->grav};
}

void Ball::applyWind()
{
	acc += {-physics->wind, 0};
}

void Ball::applyAirResistance(const float &v, const sf::Vector2f &uV) {
	if (v != 0.0f) {
		acc += dragK * pow(v, 2) * uV;
	}
}

void Ball::applyForces() {
	applyGravity();
	applyWind();
	applyAirResistance(velocity, unitVector);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const sf::Vector2f &acc, const float &t) {

	if(isballmove)applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
}

void Ball::setPixelSize(const float &pR) {
	dObject->setRadius(pR);
	realRaidus = Physics::calcRealValue(pR);
}

void Ball::update()
{
	getSimTime();
	acc = { 0.0f, 0.0f };
	
	if (!_pause) {
		if (isballmove)
		{
			std::cout << oldRealPos.x << "\n";
		oldRealPos = realPos;
		realPos = calcNewRealPos(oldRealPos, velocityVector, acc, simTime);
		
		
			velocityVector = calcVelocityVector(oldRealPos, realPos, simTime);
			
			velocity = calcVelocityFromVelocityVector(velocityVector);
			unitVector = calcUnitVector(velocityVector, velocity);
			
			dObject->setPosition(Physics::swapY(Physics::calcPixelVector(realPos)));
		}
		//std::cout << dObject->getPosition().x << " " << dObject->getPosition().y << "\n";
	}

}

Ball::~Ball() {
	Collision::getBallCollisionVector()._delete(this);
}

void Ball::test() {
	
}

