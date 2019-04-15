#pragma once

#include "Obj.h"

class Fish: public Obj
{
private:
	double saturationTime; //����� ������� �����
	double breedingTime; //����� ����������� �����
public:
	double countdownSaturationTime; //������ �������
	double countdownBreedingTime; //������ �������
public:
	Fish(double lifetime, int gender, double saturationTime, double breedingTime);
	void setSaturationTime(double saturationTime);
	double getSaturationTime();
	void setBreedingTime(double breedingTime);
	double getBreedingTime();
	void incrementTime(double deltaTime);
	~Fish();
};

