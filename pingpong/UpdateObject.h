#pragma once

class UpdateObject {

public:
	UpdateObject();
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();
	virtual ~UpdateObject();
};

