#pragma once

struct Physics {
	float resistance, pressure;
	sf::Vector2f wind;

	Physics(float resistance, float pressure, sf::Vector2f wind);

};