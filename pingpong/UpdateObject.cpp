#include "pch.h"
#include "UpdateObject.h"
#include "Game.h"

UpdateObject::UpdateObject() {
	sendUpdateObject();
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


