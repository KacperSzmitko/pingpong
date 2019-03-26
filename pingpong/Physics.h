#pragma once

struct Physics {
	float resistance;
	float pressure;
	sf::Vector2f wind;
	sf::Vector2f grav;

	Physics(float resistance, float pressure, sf::Vector2f wind, sf::Vector2f grav);

};