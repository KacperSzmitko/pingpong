#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Gameplay::Gameplay() {
	this->ball = new Ball(&physics, 100.0f, 100.0f);
	this->player1 = new Racket(&physics, 100.0f, 100.0f);

	this->ball->setVelocityVector({ 3.0f, 3.0f });

}

void Gameplay::checkCollisions() {

	for (PhysicalObject *obj : Game::getCollisionVector()->get()) {
		if (obj != ball) {
			ball->checkCollision(obj->getCollisionData());
		}
	}
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

}

void Gameplay::objectsTest() {
	ball->test();
	player1->test();
}
