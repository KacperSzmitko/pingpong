#include "pch.h"
#include "MainMenu.h"
#include "Game.h"


MainMenu::MainMenu() {
	this->start = new MenuBar(200, 100, 540, 100, "Start", [this]() {
		Game::startModeSelectMenu();
		delete this;
	});
	this->options = new MenuBar(200, 100, 540, 250, "Opcje", []() {

	});
	this->close = new MenuBar(200, 100, 540, 400, "Zamknij", []() {

	});
}

MainMenu::~MainMenu() {
	delete start;
	delete options;
	delete close;

}