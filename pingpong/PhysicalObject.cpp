#include "pch.h"
#include "Game.h"
#include "PhysicalObject.h"
#include <cmath>


PhysicalObject::PhysicalObject(float mass, Physics* physics) : mass(mass), physics(physics) {

}

PhysicalObject::~PhysicalObject() {}
