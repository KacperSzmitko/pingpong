#pragma once

struct Physics {
	float resistance, pressure, grav, pixelToRealRatio;
	sf::Vector2f wind;

	Physics(float resistance, float pressure, float grav, sf::Vector2f wind);

};