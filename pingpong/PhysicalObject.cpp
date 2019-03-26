#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(float mass, std::shared_ptr<Physics> physics) : mass(mass), physics(physics) {

}

PhysicalObject::~PhysicalObject() {}
