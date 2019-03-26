#pragma once

class UpdateObject {
public:

	sf::Time lastClock;

	UpdateObject();
	sf::Time timeDiffrence();
	
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

	virtual ~UpdateObject();
};

