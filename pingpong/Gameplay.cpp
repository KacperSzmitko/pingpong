#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay() {
	this->physics = new Physics();
	this->ball = new Ball(physics, 100.0f, 100.0f, { 5.0f, 5.0f });
	this->player1 = new Racket(physics, 100.0f, 100.0f);
	this->table = new Table(550, 10);
}

Gameplay::~Gameplay() {
	delete physics;
	delete ball;
	delete player1;
	delete table;

}
