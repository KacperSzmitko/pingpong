#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;
ObjectsVector<SimObject*> Gameplay::simVector;

Gameplay::Gameplay() {
	this->ball = new Ball(&physics, 100.0f, 100.0f);
	this->player1 = new Racket(100.0f, 100.0f);

	this->ball->setVelocityVector({ 3.0f, 3.0f });
	this->wall = new Wall(500, 50, 0, Physics::Materials::wood, 500, 100);


}

ObjectsVector<SimObject*> &Gameplay::getSimVector() {
	return simVector;
}

void Gameplay::simulateObjects() {
	simVector.forEach([](SimObject* &obj) {
		obj->simulation();
	});
}

void Gameplay::simulate() {
	simulateObjects();
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
