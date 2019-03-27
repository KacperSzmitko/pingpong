#pragma once

class UpdateObject {
protected:
	sf::Time lastTime;
	sf::Time elapsedTime;

	void CalcElapsedTime();

public:
	UpdateObject();
	
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

	virtual ~UpdateObject();
};

