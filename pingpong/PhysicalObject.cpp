#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(float mass, sf::Vector2f realSpeedVector, Physics* physics) {
	this->mass = mass;
	this->realSpeedVector = realSpeedVector;
	this->physics = physics;
	this->realSpeed = calcRealSpeedFromRealSpeedVector(realSpeedVector);
}

sf::Vector2f PhysicalObject::calcRealSpeedVector(sf::Vector2f lastPixelPos, sf::Vector2f newPixelPos, float &time) {
	return (newPixelPos - lastPixelPos) / time;
}

float PhysicalObject::calcRealSpeedFromRealSpeedVector(sf::Vector2f &realSpeedVector) {
	float ptrr = physics->pixelToRealRatio;
	return sqrt(pow((realSpeedVector.x * ptrr), 2) + pow((realSpeedVector.y * ptrr), 2));
}

PhysicalObject::~PhysicalObject() {}
