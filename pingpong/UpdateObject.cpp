#include "pch.h"
#include "UpdateObject.h"
#include "Game.h"

UpdateObject::UpdateObject() {
	sendUpdateObject();
	this->_pause = false;
}

void UpdateObject::getSimTime() {
	simTime = Game::getSimTime();
}

void UpdateObject::sendUpdateObject() {
	Game::getUpdateVector()._add(this);
}

void UpdateObject::deleteUpdateObject() {
	Game::getUpdateVector()._delete(this);
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


