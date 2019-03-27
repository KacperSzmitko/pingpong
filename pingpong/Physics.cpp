#include "pch.h"
#include "Physics.h"

Physics::Physics(float resistance, float pressure, float grav, sf::Vector2f wind) : wind(wind) {
	this->resistance = resistance;
	this->pressure = pressure;
	this->grav = grav;
	this->pixelToRealRatio = 0.005f; //Jeden piksel to 0,005 metra
};