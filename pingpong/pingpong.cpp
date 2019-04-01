#include "pch.h"
#include "Game.h"

int main() {

	Game game(1280, 720, 360, false, "Ping-Pong");
	
	game.startGameplay();

	game.run();

	return 0;
}