#include "pch.h"
#include "Ball.h"
#include "Game.h"

Ball::Ball(float posX, float posY) : 
	DrawnObject(new sf::CircleShape(BALL_DEFAULT_PIXEL_RADIUS)),
	PhysicalObject(Physics::Materials::wood, posX, posY),
	MovingObject(BALL_DEFAULT_MASS) {
	this->pixelRaidus = BALL_DEFAULT_PIXEL_RADIUS;
	this->realRaidus = Physics::calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * Physics::viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	this->dObject->setOrigin(BALL_DEFAULT_PIXEL_RADIUS, BALL_DEFAULT_PIXEL_RADIUS);
	this->dObject->setPosition(Physics::swapY({ posX, posY }));
	isballmove = false;
	p1Serv = 2; 
	p2Serv = 0; 
	p1 = false;
	p2 = false;
	pomoc = 0;
	Collision::getBallCollisionVector()._add(this);
}
   
void Ball::applyGravity() {
	acc += {0, -Physics::grav};
}

void Ball::applyWind()
{
	acc += {-Physics::wind, 0};
}

void Ball::applyAirResistance(const float &v, const sf::Vector2f &uV) {
	if (v != 0.0f) {
		acc += dragK * pow(v, 2) * uV;
	}
}

void Ball::applyForces() {
	applyGravity();
	applyWind();
	applyAirResistance(velocity, unitVector);
}

sf::Vector2f Ball::calcNewRealPos(const sf::Vector2f &lV, const sf::Vector2f &vV, const sf::Vector2f &acc, const float &t) {

	if(isballmove && (p1Serv!=2 || p2Serv!=2))applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
}

void Ball::setPixelSize(const float &pR) {
	dObject->setRadius(pR);
	realRaidus = Physics::calcRealValue(pR);
}

void Ball::update() {
	getSimTime();
	
}

void Ball::simulation() {
	acc = { 0.0f, 0.0f };
	
	
	if (!_pause) {
		
		if (isballmove)
		{
			//std::cout << "vx  " << velocityVector.x << "  vy  " << velocityVector.y << "\n";
			oldVelocityVector = velocityVector;
			
			oldRealPos = realPos;
			realPos = calcNewRealPos(oldRealPos, velocityVector, acc, simTime);
			velocityVector = calcVelocityVector(oldRealPos, realPos, simTime);
			velocity = calcVelocityFromVelocityVector(velocityVector);
			unitVector = calcUnitVector(velocityVector, velocity);
			dObject->setPosition(Physics::swapY(Physics::calcPixelVector(realPos)));
		}
		else
		{
			float pomoc = Game::getTimeForBall();
				if (pomoc !=0)
				{
					isballmove = true;
					velocityVector.y = 3.0 * pomoc;
					if (velocityVector.y > 5) velocityVector.y = 5;
					p1 = !p1;
					p2 = !p2;
					Colision = 3;
					pomoc = 0;
				}
				
		}
	}
}

Ball::~Ball() {
	Collision::getBallCollisionVector()._delete(this);
}

void Ball::test() {
	
}

