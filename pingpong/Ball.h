#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

#define BALL_DEFAULT_PIXEL_RADIUS 4.0f
#define BALL_DEFAULT_DRAG 0.47f;
#define BALL_DEFAULT_MASS 0.0025f
#define BALL_FRICTION 1.0f
#define BALL_ELASTICITY 1.0f

class Ball : public UpdateObject, public PhysicalObject, public DrawnObject<sf::CircleShape> {
private:
	float realRaidus;
	float drag;
	float dragK;

	sf::Vector2f acc;

	void applyGravity();
	void applyAirResistance(const float &velocity, const sf::Vector2f &unitVector);
	void applyForces();
	sf::Vector2f calcNewRealPos(const sf::Vector2f &lastRealPos, const sf::Vector2f &velocityVector, const sf::Vector2f &acc, const float &time);

public:
	Ball(Physics* physics, float posX, float posY);

	void setPixelSize(const float &pixelRaidus);
	void checkCollision(CollisionData *collisionData);
	void update();

	void test();
	

};


