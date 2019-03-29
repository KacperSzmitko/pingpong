#include "pch.h"
#include "Physics.h"

Physics::Physics(float resistance, float pressure, float grav, sf::Vector2f wind) : wind(wind) {
	this->resistance = resistance;
	this->pressure = pressure;
	this->grav = grav;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
};

Physics::Physics() {
	this->resistance = PHYSICS_DEFAULT_RESISTANCE;
	this->pressure = PHYSICS_DEFAULT_PRESSURE;
	this->grav = PHYSICS_DEFAULT_GRAV;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
}