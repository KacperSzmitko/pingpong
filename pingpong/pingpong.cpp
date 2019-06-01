#include "pch.h"
#include "Game.h"

int main() {

	Game game(1280, 720, 0, true, "Ping-Pong");
	
	//game.startGameplay();
	game.startMainMenu();

	game.run();

	return 0;
}