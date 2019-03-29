#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(Physics* physics, float mass, float posX, float posY, sf::Vector2f velocityVector) {
	this->physics = physics;
	this->mass = mass;
	this->lastRealPos = calcRealVector(sf::Vector2f(posX, posY));
	this->newRealPos = lastRealPos;
	this->velocityVector = velocityVector;
	this->velocity = calcVelocityFromVelocityVector(this->velocityVector);
	this->kineticEnergy = calcKineticEnergy(this->mass, this->velocity);
}

PhysicalObject::PhysicalObject(Physics* physics, float mass, float posX, float posY) {
	this->physics = physics;
	this->mass = mass;
	this->lastRealPos = calcRealVector(sf::Vector2f(posX, posY));
	this->newRealPos = lastRealPos;
	this->velocityVector = { 0.0f, 0.0f };
	this->velocity = 0.0f;
}

sf::Vector2f PhysicalObject::calcRealVector(const sf::Vector2f &pixelPos) {
	float ptrr = physics->pixelToRealRatio;
	return { pixelPos.x * ptrr, pixelPos.y * ptrr };
}

//Przeci¹¿enie, aby dzia³a³o te¿ dla wektorów intowych
sf::Vector2f PhysicalObject::calcRealVector(const sf::Vector2i &pixelPos) {
	float ptrr = physics->pixelToRealRatio;
	return { (float)pixelPos.x * ptrr, (float)pixelPos.y * ptrr };
}

sf::Vector2f PhysicalObject::calcPixelVector(const sf::Vector2f &realPos) {
	float ptrr = physics->pixelToRealRatio;
	return { (float)realPos.x / ptrr, (float)realPos.y / ptrr };
}

float PhysicalObject::calcRealValue(const float &pixelValue) {
	return pixelValue * physics->pixelToRealRatio;
}

float PhysicalObject::calcPixelValue(const float &realValue) {
	return realValue / physics->pixelToRealRatio;
}

sf::Vector2f PhysicalObject::calcVelocityVector(const sf::Vector2f &lastRealPos, const sf::Vector2f &newRealPos, const float &time) {
	return (newRealPos - lastRealPos) / time;
}

float PhysicalObject::calcVelocityFromVelocityVector(const sf::Vector2f &velocityVector) {
	return sqrt(pow((velocityVector.x), 2) + pow((velocityVector.y), 2));
}

float PhysicalObject::calcKineticEnergy(const float &mass, const float &velocity) {
	return (mass * (velocity * velocity)) / 2.0f;
}

PhysicalObject::~PhysicalObject() {}
