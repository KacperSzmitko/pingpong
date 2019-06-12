#pragma once

#include "MenuBar.h"

class BackgroundSelectMenu {
	sf::Text wybierzText;
	MenuBar *_1, *_2, *_3;
	static sf::Texture sb1, sb2, sb3;
public:
	BackgroundSelectMenu(int mode);
	~BackgroundSelectMenu();
};

