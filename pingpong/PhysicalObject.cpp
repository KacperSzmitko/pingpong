#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(float mass, sf::Vector2f speedVector, Physics* physics) {
	this->mass = mass;
	this->speedVector = speedVector;
	this->speed = calcSpeedFromSpeedVector(speedVector);
	this->physics = physics;
}

sf::Vector2f PhysicalObject::calcSpeedVector(sf::Vector2f lastPos, sf::Vector2f newPos, float &time) {
	return ((newPos - lastPos) * physics->pixelToRealRatio) / time;
}

float PhysicalObject::calcSpeedFromSpeedVector(sf::Vector2f &speedVector) {
	return sqrt(pow(speedVector.x, 2) + pow(speedVector.y, 2));
}

PhysicalObject::~PhysicalObject() {}
