#include "pch.h"
#include "UpdateObject.h"
#include "Game.h"

UpdateObject::UpdateObject() {
	sendUpdateObject();
	lastTime = Game::getTime();
}

void UpdateObject::CalcElapsedTime() {
	elapsedTime = Game::getTime() - lastTime;
	lastTime = Game::getTime();
}

void UpdateObject::sendUpdateObject() {
	Game::addUpdateObjectToUpdateVector(this);
}

void UpdateObject::deleteUpdateObject() {
	Game::deleteUpdateObjectFromUpdateVector(this);
}

UpdateObject::~UpdateObject() {
	deleteUpdateObject();
}
