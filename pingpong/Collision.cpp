#include "pch.h"
#include "Collision.h"
#include "Game.h"

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

	float lineLenghtPow = vSE.x * vSE.y + vSE.y * vSE.y;

	float t = std::max(0.0f, std::min(lineLenghtPow, vSE.x * vBS.x + vSE.y * vBS.y)) / lineLenghtPow;

	sf::Vector2f TP = SP + t * vSE;

	float distance = Physics::calcDistanceBetweenTwoPoints(TP, BP);
	
	//TEST
	sf::Vertex line[] = { sf::Vertex(TP), sf::Vertex(BP) };
	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;
	Game::getWindowObj().draw(line, 2, sf::Lines);
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
	//Tutaj

}

void Collision::ballRacketCol(Ball *ball, Racket *racket) {
	unsigned short side = ballRectCheck(ball, racket);
	if (side == 0) return;
	//TUTAJ
}

Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
}



