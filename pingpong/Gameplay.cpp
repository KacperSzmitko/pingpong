#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;
ObjectsVector<SimObject*> Gameplay::simVector;
sf::Vector2f Gameplay::default_ballLPos;
sf::Vector2f Gameplay::default_ballRPos;
sf::Vector2f Gameplay::default_racketLPos;
sf::Vector2f Gameplay::default_racketRPos;
Gameplay::Gameplay(int mode) {
	
	this->mode = mode;
	Game::getWindowObj().setMouseCursorVisible(false);
	
	this->ball = new Ball(200.0f, 300.0f);
	this->racket1 = new Racket(200.0f, 360.0f,0,1);
	this->racket2 = new Racket(1200.0f, 360.0f,mode,2);

	this->table1 = new Table(300,15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 - 155), Game::getWindowObj().getSize().y / 4, 1);
	this->table2 = new Table(300, 15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 + 150), Game::getWindowObj().getSize().y / 4, 2);
	this->net = new Table(5, 40, 0, Physics::Materials::wood, ((Game::getWindowObj().getSize().x / 2)-2.5f), (Game::getWindowObj().getSize().y / 4)+13.0f, 3);
	
	this->wallD = new Wall( Game::getWindowObj().getSize().x*10,10,0, Physics::Materials::wood,0,0);
	this->wallL = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood,0,0);
	this->wallR = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood, Game::getWindowObj().getSize().x, 0);
	
	this->player1 = new Player(0, racket1, table1,ball);
	this->player2 = new Player(mode, racket2, table2,ball);
	collision.p1 = player1;
	collision.p2 = player2;
	this->ball->setVelocityVector({ 0.0f, 0.0f });
	
	this->default_ballLPos = { 200,-360 };
	this->default_ballRPos = { 1080,-360 };
	this->default_racketLPos = { 100,-360 };
	this->default_racketRPos = { 1200,-360 };
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
	racket1->pause();
}

void Gameplay::unpause() {
	ball->unpause();
	racket1->unpause();
}

Gameplay::~Gameplay() {
	delete player1;
	delete ball;
	delete wallD, wallL, wallR;
	delete table1, table2;
	delete player1;
}

void Gameplay::objectsTest() {
	ball->test();
	racket1->test();
}
