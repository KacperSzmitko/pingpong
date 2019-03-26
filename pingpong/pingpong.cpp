#include "pch.h"
#include "Game.h"
#include "Racket.h"

int main() {

	Game game(1280, 720, 60, true, "Ping-Pong");
	
	Racket *test1 = new Racket(5, 45, 300, 300);
	Racket *test2 = new Racket(5, 45, 150, 200);
	Racket *test3 = new Racket(5, 45, 500, 500);
	Racket *test4 = new Racket(5, 45, 750, 150);

	game.run();

	return 0;
}