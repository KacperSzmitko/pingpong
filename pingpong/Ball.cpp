#include "pch.h"
#include "Ball.h"

Ball::Ball(Physics *physics, float r, float mass, float posX, float posY) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(physics, mass, posX, posY) {
	this->realRaidus = calcRealValue(r);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * physics->viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));
	
	this->start_i = 0;
}

Ball::Ball(Physics* physics, float posX, float posY) : 
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * physics->viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));

	this->start_i = 0;
}

Ball::Ball(Physics *physics, float posX, float posY, sf::Vector2f velocityVector) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(physics, BALL_DEFAULT_MASS, posX, posY, velocityVector) {
	this->realRaidus = calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * physics->viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setPosition(swapY({ posX, posY }));
	

	this->start_i = 0;
}

void Ball::applyGravity() {
	if(lastRealPos.y !=0)
	acc += {0, -physics->grav};
}

void Ball::applyAirResistance(const float &v, const sf::Vector2f &uV) {
	if (v != 0.0f) {
		acc += dragK * pow(v, 2) * uV;
	}
}

void Ball::applyWindVelocity()
{
	acc += {physics->wind, 0};
}

void Ball::applyForces() {
	applyWindVelocity();
	applyGravity();
	applyAirResistance(velocity, unitVector);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const sf::Vector2f &acc, const float &t) {

	applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
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

	lastRealPos = newRealPos;
	lastPixelPos = calcPixelVector(newRealPos);
	newPixelPos = lastPixelPos;
	//std::cout << "x: " << lastPixelPos.x << " y: " << lastPixelPos.y << "\n";

	

		if (lastPixelPos.x >= 1275.0f)
		{
			newPixelPos.x = 3.0f;
			velocityVector.x *= (-1.0f);
		}
		if (lastPixelPos.x <= 3.0f)
		{
			newPixelPos.x = 3.0f;
			velocityVector.x *= (-1.0f);
		}
		if (lastPixelPos.y < 3.0f)
		{
			newPixelPos.y = 3.0f;
			velocityVector.y *= (-1.0f);		
		}
		

	dObject->setPosition(swapY(newPixelPos));
	
	


}

