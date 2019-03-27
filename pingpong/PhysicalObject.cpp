#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"
#include <cmath>


PhysicalObject::PhysicalObject(float mass, std::shared_ptr<Physics> physics) : mass(mass), physics(physics) {

}

PhysicalObject::~PhysicalObject() {}
