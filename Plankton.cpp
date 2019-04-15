#include "Plankton.h"

#include "Obj.h"

Plankton::Plankton(double lifetime, double timeSegmentation) : Obj::Obj()
{
	setLifetime(lifetime);
	setReproduces(SEGMENTATION);
	setGender(NO_GENDER);
	this->timeSegmentation = timeSegmentation;
	this->countdownTimeSegmentation = 0.0;
}

void Plankton::incrementTime(double deltaTime) {
	Obj::incrementTime(deltaTime);
	this->countdownTimeSegmentation += deltaTime;
}

Plankton::~Plankton()
{
}
