#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;
ObjectsVector<SimObject*> Gameplay::simVector;

Gameplay::Gameplay() {
	
	this->ball = new Ball(&physics, 200.0f, 300.0f);
	this->player1 = new Racket(100.0f, 100.0f);

	this->table1 = new Table(300,15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 - 155), Game::getWindowObj().getSize().y / 4, 1);
	this->table2 = new Table(300, 15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 + 150), Game::getWindowObj().getSize().y / 4, 2);
	
	
	this->wallD = new Wall( Game::getWindowObj().getSize().x*10,10,0, Physics::Materials::wood,0,0);
	this->wallL = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood,0,0);
	this->wallR = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood, Game::getWindowObj().getSize().x, 0);
	
	this->ball->setVelocityVector({ 0.0f, 0.0f });
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
	delete table1, table2;
}

void Gameplay::objectsTest() {
	ball->test();
	player1->test();
}
