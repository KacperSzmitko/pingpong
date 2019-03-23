#pragma once
class PhysicalObject {
public:
	PhysicalObject();

	virtual void update() = 0;

	virtual ~PhysicalObject();
};

