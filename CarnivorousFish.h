#pragma once

#include "Obj.h"
#include "Fish.h"

class CarnivorousFish: public Fish
{
public:
	CarnivorousFish(double lifetime, int gender, double saturationTime, double breedingTime);
	void incrementTime(double deltaTime);
	~CarnivorousFish();
};

