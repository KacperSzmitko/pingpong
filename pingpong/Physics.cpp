#include "pch.h"
#include "Physics.h"

const float Physics::pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;

Physics::Physics(float viscosity, float grav, float wind) {
	this->viscosity = viscosity;
	this->grav = grav;
	this->wind = wind;
};

Physics::Physics() {
	this->viscosity = PHYSICS_DEFAULT_VISCOSITY;
	this->grav = PHYSICS_DEFAULT_GRAV;
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

sf::Vector2f Physics::calcRealVector(const sf::Vector2f &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { pixelVector.x * ptrr, pixelVector.y * ptrr };
}

//Przeci¹¿enie, aby dzia³a³o te¿ dla wektorów intowych
sf::Vector2f Physics::calcRealVector(const sf::Vector2i &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { (float)pixelVector.x * ptrr, (float)pixelVector.y * ptrr };
}

sf::Vector2f Physics::calcPixelVector(const sf::Vector2f &realVector) {
	float ptrr = pixelToRealRatio;
	return { (float)realVector.x / ptrr, (float)realVector.y / ptrr };
}

float Physics::calcRealValue(const float &pixelValue) {
	return pixelValue * pixelToRealRatio;
}

float Physics::calcPixelValue(const float &realValue) {
	return realValue / pixelToRealRatio;
}

sf::Vector2f Physics::swapY(const sf::Vector2f &pos) {
	return { pos.x, -pos.y };
}