#include "pch.h"
#include "SimObject.h"
#include "Game.h"

SimObject::SimObject() {
	sendSimObject();
	this->_pause = false;
	this->simPerFrame = Game::getSimPerFrame();
}

void SimObject::getSimTime() {
	simTime = Game::getSimTime();
}

void SimObject::sendSimObject() {
	Gameplay::getSimVector()._add(this);
}

void SimObject::deleteSimObject() {
	Gameplay::getSimVector()._delete(this);
}

void SimObject::pause() {
	_pause = true;
}
void SimObject::unpause() {
	_pause = false;
}

SimObject::~SimObject() {
	deleteSimObject();
}