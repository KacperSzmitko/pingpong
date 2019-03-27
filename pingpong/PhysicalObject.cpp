#include "pch.h"
#include "PhysicalObject.h"
#include "Game.h"
#include <cmath>



PhysicalObject::PhysicalObject(float mass,Physics *physics) :
	mass(mass), Ek(Ek), Ep(Ep), momentum(momentum), speed(speed), acceleration(acceleration),physics(physics) {};

sf::Time PhysicalObject::timeDiffrence() {
	return Game::getTime() - last_clock;
}




PhysicalObject::~PhysicalObject() {}
