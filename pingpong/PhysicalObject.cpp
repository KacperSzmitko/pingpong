#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(Physics* physics, float mass, float friction, float elasticity, float posX, float posY) {
	this->physics = physics;
	this->mass = mass;
	this->friction = friction;
	this->elasticity = elasticity;
	this->newRealPos = calcRealVector(sf::Vector2f(posX, posY));
	this->lastRealPos = newRealPos;
	this->velocityVector = { 0.0f, 0.0f };
	this->velocity = 0.0f;

	Game::addCollisionObjectToCollisionVector(this);
}

//*****PRIVATE*****

sf::Vector2f PhysicalObject::calcRealVector(const sf::Vector2f &pixelVector) {
	float ptrr = physics->pixelToRealRatio;
	return { pixelVector.x * ptrr, pixelVector.y * ptrr };
}

//Przeci¹¿enie, aby dzia³a³o te¿ dla wektorów intowych
sf::Vector2f PhysicalObject::calcRealVector(const sf::Vector2i &pixelVector) {
	float ptrr = physics->pixelToRealRatio;
	return { (float)pixelVector.x * ptrr, (float)pixelVector.y * ptrr };
}

sf::Vector2f PhysicalObject::calcPixelVector(const sf::Vector2f &realVector) {
	float ptrr = physics->pixelToRealRatio;
	return { (float)realVector.x / ptrr, (float)realVector.y / ptrr };
}

float PhysicalObject::calcRealValue(const float &pixelValue) {
	return pixelValue * physics->pixelToRealRatio;
}

float PhysicalObject::calcPixelValue(const float &realValue) {
	return realValue / physics->pixelToRealRatio;
}

sf::Vector2f PhysicalObject::swapY(const sf::Vector2f &pos) {
	return { pos.x, -pos.y };
}

sf::Vector2f PhysicalObject::calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &time) {
	return (newRealPos - lastRealPos) / time;
}

float PhysicalObject::calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector) {
	return sqrt(pow((velocityVector.x), 2) + pow((velocityVector.y), 2));
}

sf::Vector2f PhysicalObject::calcUnitVector(const sf::Vector2f &velocityVector, const float &velocity) {
	return velocityVector / velocity;
}

float PhysicalObject::calcKineticEnergy(const float &mass, const float &velocity) {
	return (mass * (velocity * velocity)) / 2.0f;
}

//*****PUBLIC*****

void PhysicalObject::setMass(const float &m) {
	mass = m;
}

void PhysicalObject::setVelocityVector(const sf::Vector2f &vV) {
	velocityVector = vV;
	velocity = calcVelocityFromVelocityVector(velocityVector);
}

void PhysicalObject::setRealPos(const sf::Vector2f &rP) {
	newRealPos = rP;
	lastRealPos = newRealPos;
}



PhysicalObject::~PhysicalObject() {
	Game::deleteCollisionObjectFromCollisionVector(this);
}
