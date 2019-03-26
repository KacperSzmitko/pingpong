#include "pch.h"
#include "Game.h"
#include "Racket.h"

int main() {

	Game game(1280, 720, 60, false, "Ping-Pong");

	Racket r(5, 30, 100, 100, 1, nullptr);
	

	game.run();

	return 0;
}