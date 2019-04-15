#include "Fish.h"

#include "Obj.h"

Fish::Fish(double lifetime, int gender, double saturationTime, double breedingTime) : Obj::Obj()
{
	setLifetime(lifetime);
	setReproduces(GENITAL);
	setGender(gender);
	setSaturationTime(saturationTime);
	setBreedingTime(breedingTime);
	this->countdownSaturationTime = 0;
	this->countdownBreedingTime = 0;
}

void Fish::setSaturationTime(double saturationTime) {
	this->saturationTime = saturationTime;
}

double Fish::getSaturationTime() {
	return this->saturationTime;
}

void Fish::setBreedingTime(double breedingTime) {
	this->breedingTime = breedingTime;
}

double Fish::getBreedingTime() {
	return this->breedingTime;
}

void Fish::incrementTime(double deltaTime) {
	Obj::incrementTime(deltaTime);
	this->countdownSaturationTime += deltaTime;
	this->countdownBreedingTime += deltaTime;
}


Fish::~Fish()
{
}
