#include "CarnivorousFish.h"

#include "Obj.h"
#include "Fish.h"

CarnivorousFish::CarnivorousFish(double lifetime, int gender, double saturationTime, double breedingTime)
	: Fish(lifetime, gender, saturationTime, breedingTime)
{
}

void CarnivorousFish::incrementTime(double deltaTime) {
	Fish::incrementTime(deltaTime);
}

CarnivorousFish::~CarnivorousFish()
{
}
