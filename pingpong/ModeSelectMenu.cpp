#include "pch.h"
#include "ModeSelectMenu.h"
#include "Game.h"


ModeSelectMenu::ModeSelectMenu() {
	this->PVP = new MenuBar(300, 100, 490, 50, "Gracz vs Gracz", [this]() {
		Game::startBackgroundSelectMenu(0);
		delete this;
	});
	this->PVC = new MenuBar(300, 100, 490, 200, "Gracz vs Komputer", [this]() {
		Game::startBackgroundSelectMenu(1);
		delete this;
	});
	this->FP = new MenuBar(300, 100, 490, 350, "Gra dowolna", [this]() {
		Game::startBackgroundSelectMenu(2);
		delete this;
	});
	this->back = new MenuBar(200, 100, 540, 500, L"Powrót", [this]() {
		Game::startMainMenu();
		delete this;
	});

}


ModeSelectMenu::~ModeSelectMenu() {
	delete PVP;
	delete PVC;
	delete FP;
	delete back;
}
