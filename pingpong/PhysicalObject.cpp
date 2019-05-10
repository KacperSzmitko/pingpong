#include "pch.h"
#include "PhysicalObject.h"
#include "Physics.h"
#include "Game.h"

PhysicalObject::PhysicalObject(Physics::Material material, float pixelPosX, float pixelPosY) {
	this->material = material;
	this->realPos = Physics::calcRealVector(sf::Vector2f(pixelPosX, pixelPosY));
}



