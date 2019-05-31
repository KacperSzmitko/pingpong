#include "pch.h"
#include "ModeSelectMenu.h"
#include "Game.h"


ModeSelectMenu::ModeSelectMenu() {
	this->PVP = new MenuBar(300, 100, 490, 100, "Gracz vs Gracz", [this]() {
		Game::startGameplay(0);
		delete this;
	});
	this->PVC = new MenuBar(300, 100, 490, 250, "Gracz vs Komputer", [this]() {
		Game::startGameplay(1);
		delete this;
	});
	this->back = new MenuBar(200, 100, 540, 400, "Powrot", [this]() {
		Game::startMainMenu();
		delete this;
	});

}


ModeSelectMenu::~ModeSelectMenu() {
	delete PVP;
	delete PVC;
	delete back;
}
