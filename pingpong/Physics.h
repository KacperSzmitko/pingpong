#pragma once

struct Physics {
	float resistance, pressure,tendency;
	sf::Vector2f wind;

	Physics(float resistance, float pressure, sf::Vector2f wind);

};