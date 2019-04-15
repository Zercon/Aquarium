#pragma once

#include "Obj.h"

class Fish: public Obj
{
private:
	double saturationTime; //время сытости рыбки
	double breedingTime; //время размножения рыбки
public:
	double countdownSaturationTime; //отсчет времени
	double countdownBreedingTime; //отсчет времени
public:
	Fish(double lifetime, int gender, double saturationTime, double breedingTime);
	void setSaturationTime(double saturationTime);
	double getSaturationTime();
	void setBreedingTime(double breedingTime);
	double getBreedingTime();
	void incrementTime(double deltaTime);
	~Fish();
};

