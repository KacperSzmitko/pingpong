#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

#define BALL_DEFAULT_PIXEL_RADIUS 4.0f
#define BALL_DEFAULT_DRAG 0.47f;
#define BALL_DEFAULT_MASS 0.0025f

class Ball : public UpdateObject, public PhysicalObject, public DrawnObject<sf::CircleShape>
{
private:
	float realRaidus;
	float crossSectionArea;
	float drag;
	sf::Vector2f acc;

	void applyGravity();
	void applyAirResistance(const sf::Vector2f &velocityVector, const float &velocity);
	void applyForces();
	sf::Vector2f calcNewRealPos(const sf::Vector2f &lastRealPos, const sf::Vector2f &velocityVector, const sf::Vector2f &acc, const float &time);

public:
	Ball(Physics* physics, float realRaidus, float mass, float posX, float posY);
	Ball(Physics* physics, float posX, float posY);
	Ball(Physics* physics, float posX, float posY, sf::Vector2f velocityVector);
	void update();
	

};


