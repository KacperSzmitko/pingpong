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
	float angle;
	float tgalfa;
	if (side == 0) return;
	else if (p1 && side==1)
	{
		//Jesli pileczka spada pionowo w dol a2 = 0 
		ball->isballmove = true;
		float a2;
		if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
			a2 = 0;
		else
		{
			sf::Vector2f oldBallPosPix = Physics::calcPixelVector(ball->oldRealPos);
			sf::Vector2f BallPosPix = Physics::calcPixelVector(ball->realPos);
			if (oldBallPosPix.x == BallPosPix.x || oldBallPosPix.y == BallPosPix.y)
			{
				a2 = 0;
			}
			else
			a2 = Physics::calcDirectionFactor(oldBallPosPix.x, oldBallPosPix.y, BallPosPix.x, BallPosPix.y);
		}
		
		
		if (SP.y == EP.y)
		{
			tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
			tgalfa -= 1.57079;
		}
		else if (SP.x == EP.x)
		{
			tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
		}
		else
		{
			float a1 = Physics::calcDirectionFactor(SP.x, SP.y, EP.x, EP.y);
			tgalfa = abs(((a2 - a1) / (1 + a1 * a2)));
			tgalfa = atan(tgalfa);
			tgalfa -= 1.570796;
		}
		
		angle = tgalfa;
		if (angle > 1.4) angle = 1.3;
		else if (angle < -1.4) angle = -1.3;
		
		/*
		if ((ball->unitVector.x < 0 && racket->unitVector.x >0) || ((ball->unitVector.x > 0 && racket->unitVector.x < 0)))
		{
			ball->velocityVector = { Physics::calcRealValue((((racket->mass*racket->velocityVector.x) - (ball->mass*ball->velocityVector.x) + (racket->mass*racket->velocityVector.x)) / (ball->mass*cos(angle)))),
			Physics::calcRealValue((((racket->mass*racket->velocityVector.y) - (ball->mass*ball->velocityVector.y) + (racket->mass*racket->velocityVector.y)) / (ball->mass*sin(angle)))) };
		}
		*/
		if ((ball->unitVector.x <= 0 && racket->unitVector.x >=0) || ((ball->unitVector.x >= 0 && racket->unitVector.x <= 0)))
		{
			ball->velocityVector = { ((racket->velocityVector.x -ball->velocityVector.x )*racket->mass*cos(angle)
				+ (racket->velocityVector.x*racket->mass) + (ball->mass*ball->velocityVector.x)) / ((racket->mass + ball->mass)*cos(angle)),
				((racket->velocityVector.y - ball->velocityVector.y)*racket->mass*sin(angle)
				+ (racket->velocityVector.y*racket->mass) + (ball->mass*ball->velocityVector.y)) / ((racket->mass + ball->mass)*sin(angle))

			};
			
		}
		else if (racket->velocityVector.x == 0 && racket->velocityVector.y == 0)
		{
			ball->velocityVector = { ball->velocityVector.x/cos(angle) , ball->velocityVector.y/sin(angle)  };
			
		}
		else if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
		{
			ball->velocityVector = { (racket->velocityVector.x*racket->mass*cos(angle)
				+ (racket->velocityVector.x*racket->mass)) / ((racket->mass + ball->mass)*cos(angle)),
			(racket->velocityVector.y*racket->mass*sin(angle)
				+ (racket->velocityVector.y*racket->mass)) / -((racket->mass + ball->mass)*sin(angle)) };

		}
		std::cout << angle << "\n";
		p1 = !p1;
		p2 = !p2;
	}


}

Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
}



