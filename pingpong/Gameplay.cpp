#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay() : physics(), player1(&physics, 100, 100), ball(&physics, 150, 150) {

}


Gameplay::~Gameplay() {}
