#pragma once

struct Physics {
	float resistance, pressure, grav;
	sf::Vector2f wind;
	float pixelToRealRatio;

	Physics(float resistance, float pressure, sf::Vector2f wind, float grav);

};