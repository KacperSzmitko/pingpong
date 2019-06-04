#pragma once

#include "TextOption.h"
#include "MenuBar.h"

class PhysicsSettingsMenu {
private:
	TextOption *viscosityOption;
	TextOption *gravOption;
	TextOption *windOption;
	MenuBar *reset, *back;

public:
	PhysicsSettingsMenu();
	~PhysicsSettingsMenu();
};

