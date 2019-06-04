#include "pch.h"
#include "PhysicsSettingsMenu.h"
#include "Physics.h"
#include "Game.h"

PhysicsSettingsMenu::PhysicsSettingsMenu() {
	this->viscosityOption = new TextOption(100.0f, 100.0f, L"Gêstoœæ powietrza: ", &(Physics::viscosity), 0.1f, 10.0f, false);
	this->gravOption = new TextOption(100.0f, 200.0f, L"Grawitacja: ", &(Physics::grav), 1.0f, 100.0f, false);
	this->windOption = new TextOption(100.0f, 300.0f, L"Wiatr: ", &(Physics::wind), 0.2f, 20.0f, true);
	this->reset = new MenuBar(200, 100, 980, 75, "Resetuj", []() {
		Physics::resetValues();
	});
	this->back = new MenuBar(200, 100, 980, 275, L"Powrót", [this]() {
		Game::startMainMenu();
		delete this;
	});

}


PhysicsSettingsMenu::~PhysicsSettingsMenu() {
	delete viscosityOption;
	delete gravOption;
	delete windOption;
	delete back;
	delete reset;
}
