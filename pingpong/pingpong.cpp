#include "pch.h"
#include "Game.h"
#include "Racket.h"

int main() {

	Game game(1280, 720, 60, true, "Ping-Pong");

	

	game.run();

	return 0;
}