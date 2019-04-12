#include "pch.h"
#include "Physics.h"

Physics::Physics(float viscosity, float pressure, float grav, sf::Vector2f wind) : wind(wind) {
	this->viscosity = viscosity;
	this->pressure = pressure;
	this->grav = grav;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
};

Physics::Physics() {
	this->viscosity = PHYSICS_DEFAULT_VISCOSITY;
	this->pressure = PHYSICS_DEFAULT_PRESSURE;
	this->grav = PHYSICS_DEFAULT_GRAV;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
}