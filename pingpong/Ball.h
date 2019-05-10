#pragma once

#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "MovingObject.h"
#include "Physics.h"

#define BALL_DEFAULT_PIXEL_RADIUS 4.0f
#define BALL_DEFAULT_DRAG 0.47f;
#define BALL_DEFAULT_MASS 0.0025f

class Ball : public PhysicalObject, public MovingObject, public DrawnObject<sf::CircleShape> {
	
	friend class Collision;

private:
	Physics *physics;
	float pixelRaidus, realRaidus;
	float drag;
	float dragK;
	bool isballmove;
	sf::Vector2f acc;

	void applyGravity();
	void applyWind();
	void applyAirResistance(const float &velocity, const sf::Vector2f &unitVector);
	void applyForces();
	sf::Vector2f calcNewRealPos(const sf::Vector2f &lastRealPos, const sf::Vector2f &velocityVector, const sf::Vector2f &acc, const float &time);

public:
	Ball(Physics* physics, float posX, float posY);

	void setPixelSize(const float &pixelRaidus);
	void update();

	~Ball();

	void test();
	

};


