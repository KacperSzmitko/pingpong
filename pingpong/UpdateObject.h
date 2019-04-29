#pragma once

class UpdateObject {
protected:
	float lastTime;
	float elapsedTime;
	bool _pause;

	void calcElapsedTime();

public:
	UpdateObject();
	
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

	void pause();
	void unpause();

	virtual ~UpdateObject();
};

