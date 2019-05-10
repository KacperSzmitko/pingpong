#pragma once

class UpdateObject {
protected:
	float simTime;
	bool _pause;

	void getSimTime();

public:
	UpdateObject();
	
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

	void pause();
	void unpause();

	virtual ~UpdateObject();
};

