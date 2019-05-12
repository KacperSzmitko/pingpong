#pragma once
class SimObject {
private:
	virtual void sendSimObject();
	virtual void deleteSimObject();

protected:
	float simTime;
	int simPerFrame;
	bool _pause;

	void getSimTime();

public:
	SimObject();
	virtual void simulation() = 0;
	void pause();
	void unpause();
	virtual ~SimObject();
};

