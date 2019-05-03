#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay() {
	this->physics = new Physics(1.225f,1.4,0);
	this->ball = new Ball(physics, 100.0f, 100.0f, { 1.0f, 1.0f });
	this->player1 = new Racket(physics, 100.0f, 100.0f);
	this->table = new Table(550, 10);
}

Gameplay::~Gameplay() {
	delete physics;
	delete ball;
	delete player1;
	delete table;

}
