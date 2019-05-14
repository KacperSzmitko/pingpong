#include "pch.h"
#include "Collision.h"
#include "Game.h"
#include <cmath>

ObjectsVector<Wall*> Collision::walls;
ObjectsVector<Racket*> Collision::rackets;
ObjectsVector<Ball*> Collision::balls;

ObjectsVector<Wall*> &Collision::getWallCollisionVector() {
	return walls;
}

ObjectsVector<Racket*> &Collision::getRacketCollisionVector() {
	return rackets;
}

ObjectsVector<Ball*> &Collision::getBallCollisionVector() {
	return balls;
}

void Collision::checkCollisions() {
	
	//Balls and walls
	balls.forEach([this](Ball *ball) {
		walls.forEach([this, ball](Wall *wall) {
			ballWallCol(ball, wall);
		});
	});

	//Balls and rackets
	balls.forEach([this](Ball *ball) {
		rackets.forEach([this, ball](Racket *racket) {
			ballRacketCol(ball, racket);
		});
	});
}

unsigned short Collision::ballRectCheck(Ball *ball, Rect *rect) {
	sf::Vector2f BP = ball->dObject->getPosition();
	sf::Transform trans = rect->dObject->getTransform();
	sf::Vector2f EP = trans * rect->localEP;
	sf::Vector2f SP = trans * rect->localSP;

	sf::Vector2f vSE = EP - SP;
	sf::Vector2f vBS = BP - SP;

	float lineLenghtPow = vSE.x * vSE.x + vSE.y * vSE.y;

	float t = std::max(0.0f, std::min(lineLenghtPow, vSE.x * vBS.x + vSE.y * vBS.y)) / lineLenghtPow;

	sf::Vector2f TP = SP + t * vSE;

	float distance = Physics::calcDistanceBetweenTwoPoints(TP, BP);
	
	//TEST
	//sf::Vertex line[] = { sf::Vertex(TP), sf::Vertex(BP) };
	//line[0].color = sf::Color::Red;
	//line[1].color = sf::Color::Red;
	//Game::getWindowObj().draw(line, 2, sf::Lines);
	//TEST

	if (distance <= ball->pixelRaidus + rect->pixelRadius) {
		if (t == 0 || t == 1) return 2;
		return 1;
		
	} else {
		return 0;
	}
}

void Collision::ballWallCol(Ball *ball, Wall *wall) {
	unsigned short side = ballRectCheck(ball, wall);
	if (side == 0) return;
	else
	{
		
		ball->dObject->setPosition(300, -300);
		ball->velocityVector = { 0.0f, 0.0f };
		ball->realPos = { ball->physics->calcRealValue(ball->dObject->getPosition().x),
		-ball->physics->calcRealValue(ball->dObject->getPosition().y) };
		ball->isballmove = false;
		p1 = !p1;
		p2 = !p2;
		
	}
}

void Collision::ballRacketCol(Ball *ball, Racket *racket) {
	unsigned short side = ballRectCheck(ball, racket);
	sf::Transform trans = racket->dObject->getTransform();
	sf::Vector2f SP = trans * racket->localSP;
	sf::Vector2f EP = trans * racket->localEP;
	if (side == 0) return;
	else if (p1)
	{
		ball->isballmove = true;
		float a2;
		if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
			a2 = 0;
		else
		{
			sf::Vector2f oldBallPosPix = Physics::calcPixelVector(ball->oldRealPos);
			sf::Vector2f BallPosPix = Physics::calcPixelVector(ball->realPos);
			a2 = Physics::calcDirectionFactor(oldBallPosPix.x, oldBallPosPix.y, BallPosPix.x, BallPosPix.y);
		}
		float a1 = Physics::calcDirectionFactor(SP.x, SP.y, EP.x, EP.y);
		if (SP.x == EP.x) a1 = 0;
		else if (SP.y == EP.y) a1 = 0;


		float tgalfa = abs(((a2 - a1) / (1 + a1 * a2)));
		float angle =  1.570796 - atan(tgalfa) ;
		std::cout << angle * (180/3.1415) << "\n";

		/*
		if ((ball->unitVector.x < 0 && racket->unitVector.x >0) || ((ball->unitVector.x > 0 && racket->unitVector.x < 0)))
		{
			ball->velocityVector = { Physics::calcRealValue((((racket->mass*racket->velocityVector.x) - (ball->mass*ball->velocityVector.x) + (racket->mass*racket->velocityVector.x)) / (ball->mass*cos(angle)))),
			Physics::calcRealValue((((racket->mass*racket->velocityVector.y) - (ball->mass*ball->velocityVector.y) + (racket->mass*racket->velocityVector.y)) / (ball->mass*sin(angle)))) };
		}
		*/
		if ((ball->unitVector.x < 0 && racket->unitVector.x >0) || ((ball->unitVector.x > 0 && racket->unitVector.x < 0)))
		{
			ball->velocityVector = { ((ball->velocityVector.x + racket->velocityVector.x)*racket->mass*cos(angle)
				+ (racket->velocityVector.x*racket->mass) - (ball->mass*ball->velocityVector.x)) / (racket->mass + ball->mass)*cos(angle),
				((ball->velocityVector.y + racket->velocityVector.y)*racket->mass*sin(angle)
				+ (racket->velocityVector.y*racket->mass) - (ball->mass*ball->velocityVector.y)) / (racket->mass + ball->mass)*sin(angle)

			};
			std::cout << ball->velocityVector.x << "  " << ball->velocityVector.y << "\n";
		}
		else if (racket->velocityVector.x == 0 && racket->velocityVector.y == 0)
		{
			ball->velocityVector = { -ball->velocityVector.x / cos(angle),ball->velocityVector.y / sin(angle) };
			std::cout << ball->velocityVector.x << "  " << ball->velocityVector.y << "\n";
		}
		else if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
		{
			ball->velocityVector = { ((racket->velocityVector.x - ball->velocityVector.x)*racket->mass*cos(angle)
				+ (racket->velocityVector.x*racket->mass) + (ball->mass*ball->velocityVector.x)) / (racket->mass + ball->mass)*cos(angle),
			((racket->velocityVector.y - ball->velocityVector.y)*racket->mass*sin(angle)
				+ (racket->velocityVector.y*racket->mass) + (ball->mass*ball->velocityVector.y)) / (racket->mass + ball->mass)*sin(angle) };

		}
		p1 = !p1;
		p2 = !p2;
	}

}

Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
}



