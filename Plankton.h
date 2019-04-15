#pragma once

#include "Obj.h"

class Plankton: public Obj
{
public:
	double timeSegmentation;
	double countdownTimeSegmentation;
public:
	Plankton(double lifetime, double timeSegmentation);
	void incrementTime(double deltaTime);
	~Plankton();
};

