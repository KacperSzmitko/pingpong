#pragma once

class UpdateObject {
protected:
	float lastTime;
	float elapsedTime;

	void calcElapsedTime();

public:
	UpdateObject();
	
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

	virtual ~UpdateObject();
};

