#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

ObjectsVector<Rect*> Gameplay::rectCollisionVector;

Gameplay::Gameplay() {
	this->ball = new Ball(&physics, 100.0f, 100.0f);
	this->player1 = new Racket(100.0f, 100.0f);
	

	this->ball->setVelocityVector({ 3.0f, 3.0f });

}

ObjectsVector<Rect*> &Gameplay::getRectCollisionVector() {
	return rectCollisionVector;
}

void Gameplay::checkCollisions() {
	
}

void Gameplay::pause() {
	ball->pause();
	player1->pause();
}

void Gameplay::unpause() {
	ball->unpause();
	player1->unpause();
}

Gameplay::~Gameplay() {
	delete player1;
	delete ball;
	rectCollisionVector.clear();
}

void Gameplay::objectsTest() {
	ball->test();
	player1->test();
}
