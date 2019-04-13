#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay() {
	this->physics = new Physics();
	this->ball = new Ball(physics, 100.0f, 100.0f);
	this->player1 = new Racket(physics, 100.0f, 100.0f);

	this->ball->setVelocityVector({ 3.0f, 3.0f });

}

Gameplay::~Gameplay() {
	delete physics;
	delete player1;
	delete ball;

}
