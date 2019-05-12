#pragma once
class SymObject {
protected:
	float simTime;
	bool _pause;
	void getSimTime();
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();

public:
	SymObject();
	void pause();
	void unpause();
	virtual ~SymObject();
};

