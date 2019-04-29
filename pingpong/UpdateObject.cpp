#include "pch.h"
#include "UpdateObject.h"
#include "Game.h"

UpdateObject::UpdateObject() {
	sendUpdateObject();
	this->lastTime = Game::getTime();
	this->_pause = false;
}

void UpdateObject::calcElapsedTime() {
	elapsedTime = Game::getTime() - lastTime;
	lastTime = Game::getTime();
}

void UpdateObject::sendUpdateObject() {
	Game::addUpdateObjectToUpdateVector(this);
}

void UpdateObject::deleteUpdateObject() {
	Game::deleteUpdateObjectFromUpdateVector(this);
}

void UpdateObject::pause() {
	_pause = true;
}
void UpdateObject::unpause() {
	_pause = false;
}

UpdateObject::~UpdateObject() {
	deleteUpdateObject();
}


