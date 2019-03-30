#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay() : physics(), player1(&physics, 100, 100), ball(&physics, 100, 100, { 3.5f, 3.5f }) {

}

Gameplay::~Gameplay() {}
