#include "pch.h"
#include "PhysicalObject.h"
#include "Physics.h"

PhysicalObject::PhysicalObject(float friction, float elasticity, float pixelPosX, float pixelPosY) {
	this->friction = friction;
	this->elasticity = elasticity;
	this->realPos = Physics::calcRealVector(sf::Vector2f(pixelPosX, pixelPosY));
}


