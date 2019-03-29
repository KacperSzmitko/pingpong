#pragma once

#define PHYSICS_DEFAULT_RESISTANCE 1.0f
#define PHYSICS_DEFAULT_PRESSURE 1.0f
#define PHYSICS_DEFAULT_GRAV 1.0f
#define PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO 0.005f //Jeden piksel to 0,005 metra

struct Physics {
	float resistance, pressure, grav, pixelToRealRatio;
	sf::Vector2f wind;

	Physics(float resistance, float pressure, float grav, sf::Vector2f wind);
	Physics();



};