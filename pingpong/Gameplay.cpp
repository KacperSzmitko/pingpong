#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;
ObjectsVector<SimObject*> Gameplay::simVector;

Gameplay::Gameplay() {
	this->ball = new Ball(&physics, 100.0f, -100.0f);
	this->player1 = new Racket(100.0f, 100.0f);

	this->ball->setVelocityVector({ 3.0f, 6.0f });
	this->wallD = new Wall( Game::getWindowObj().getSize().x*2,3,0, Physics::Materials::wood,0,0);
	this->wallL = new Wall(3, Game::getWindowObj().getSize().y * 2, 0, Physics::Materials::wood,0,0);
	this->wallR = new Wall(3, Game::getWindowObj().getSize().y * 2, 0, Physics::Materials::wood, Game::getWindowObj().getSize().x, 0);

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
	delete wallD, wallL, wallR;
}

void Gameplay::objectsTest() {
	ball->test();
	player1->test();
}
