#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;

Gameplay::Gameplay() {
	this->ball = new Ball(&physics, 100.0f, 100.0f);
	this->player1 = new Racket(100.0f, 100.0f);
	this->wallD = new Wall(3, Game::getWindowObj().getSize().x, 90, Physics::Materials::wood,
		640, 0);
	this->ball->setVelocityVector({ 4.0f, 3.0f });


}

void Gameplay::checkCollisions() {
	collision.checkCollisions();
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
