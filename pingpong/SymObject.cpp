#include "pch.h"
#include "SymObject.h"


SymObject::UpdateObject() {
	sendUpdateObject();
	this->_pause = false;
}

void SymObject::getSimTime() {
	simTime = Game::getSimTime();
}

void SymObject::sendSymObject() {
	Game::getUpdateVector()._add(this);
}

void SymObject::deleteSymObject() {
	Game::getUpdateVector()._delete(this);
}

void SymObject::pause() {
	_pause = true;
}
void SymObject::unpause() {
	_pause = false;
}

SymObject::~UpdateObject() {
	deleteUpdateObject();
}
