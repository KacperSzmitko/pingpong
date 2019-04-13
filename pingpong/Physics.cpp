#include "pch.h"
#include "Physics.h"

Physics::Physics(float viscosity, float grav, float wind) {
	this->viscosity = viscosity;
	this->grav = grav;
	this->wind = wind;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
};

Physics::Physics() {
	this->viscosity = PHYSICS_DEFAULT_VISCOSITY;
	this->grav = PHYSICS_DEFAULT_GRAV;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
	this->wind = 0.0f;
}

void Physics::setViscosity(const float &v) {
	viscosity = v;
}

void Physics::setPressure(const float &p) {
	pressure = p;
}

void Physics::setGrav(const float &g) {
	grav = g;
}

void Physics::setWind(const float &w) {
	wind = w;
}