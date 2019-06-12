#include "pch.h"
#include "Gameplay.h"
#include "Game.h"

Collision Gameplay::collision;
ObjectsVector<SimObject*> Gameplay::simVector;
sf::Vector2f Gameplay::default_ballLPos;
sf::Vector2f Gameplay::default_ballRPos;
sf::Vector2f Gameplay::default_racketLPos;
sf::Vector2f Gameplay::default_racketRPos;
int Gameplay::player1Score = 0;
int Gameplay::player2Score = 0;

Gameplay::Gameplay(int mode) {
	
	this->mode = mode;
	Game::getWindowObj().setMouseCursorVisible(false);
	this->ball = new Ball(200.0f, 300.0f);
	this->racket1 = new Racket(150.0f, 360.0f,0,1);
	this->racket2 = new Racket(1130.0f, 360.0f,mode,2);

	this->table1 = new Table(340,15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 - 175), Game::getWindowObj().getSize().y / 4, 1);
	this->table2 = new Table(340, 15, 0, Physics::Materials::wood, (Game::getWindowObj().getSize().x / 2 + 170), Game::getWindowObj().getSize().y / 4, 2);
	this->net = new Table(5, 30, 0, Physics::Materials::wood, ((Game::getWindowObj().getSize().x / 2)-2.5f), (Game::getWindowObj().getSize().y / 4)+23.0f, 3);
	
	this->wallD = new Wall( Game::getWindowObj().getSize().x*10,10,0, Physics::Materials::wood,0,0);
	this->wallL = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood,0,0);
	this->wallR = new Wall(10, Game::getWindowObj().getSize().y * 10, 0, Physics::Materials::wood, Game::getWindowObj().getSize().x, 0);
	
	this->player1 = new Player(mode, racket1, table1,ball, 1);
	this->player2 = new Player(mode, racket2, table2,ball, 2);
	collision.p1 = player1;
	collision.p2 = player2;
	this->ball->setVelocityVector({ 0.0f, 0.0f });
	
	this->default_ballLPos = { 200,-360 };
	this->default_ballRPos = { 1080,-360 };
	this->default_racketLPos = { 150,-360 };
	this->default_racketRPos = { 1130,-360 };

	this->player1Score = 0;
	this->player2Score = 0;

	sf::Mouse::setPosition(Game::getWindowObj().mapCoordsToPixel({ 200.0f, -360.0f }), Game::getWindowObj());
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

void Gameplay::update() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		Game::startMainMenu();
		Game::getWindowObj().setMouseCursorVisible(true);
		Game::gameplay = nullptr;
		delete this;
	}
}

Gameplay::~Gameplay() {
	delete ball;
	delete wallD;
	delete wallL;
	delete wallR;
	delete table1;
	delete table2;
	delete net;
	delete racket1;
	delete racket2;
	delete player1;
	delete player2;
}

void Gameplay::objectsTest() {
	ball->test();
	racket1->test();
}
