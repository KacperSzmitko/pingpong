#pragma once

struct Physics {
	float resistance, pressure,grav;
	sf::Vector2f wind;

	Physics(float resistance, float pressure, sf::Vector2f wind, float grav);

};