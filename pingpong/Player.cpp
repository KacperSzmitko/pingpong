#include "pch.h"
#include "Player.h"

Player::Player(int mode, Racket* racket, Table* table) {
	this->mode = mode;
	this->racket = racket;
	this->table = table;
	this->points = 0;
}

void Player::move() {
	if (mode == 0) {
		racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
		//Po zdobyciu punktu myszka bedzie przeskakiwala
	} else if (mode == 1) {
		//tutaj AI
	}
}

void Player::setPoints(int points) {
	this->points = points;
}

int Player::getPoints() {
	return points;
}

void Player::simulation() {
	move();
}

Player::~Player() {}
