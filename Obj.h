#pragma once

#define SEGMENTATION 1
#define GENITAL 2

#define NO_GENDER 0
#define MALE 1
#define FEMALE 2

class Obj
{
private:
	double lifetime; //время жизни
	int reproduces; //тип размножения
	int gender; //пол
	double time; //прожитое время
public:
	double x, y;
	double sx, sy;
public:
	void setPosition(double x, double y);
	void setLifetime(double lifetime);
	double getLifetime();
	void setReproduces(int reproduces);
	int getReproduced();
	void setGender(int gender);
	int getGender();
	void setTime(double time);
	void incrementTime(double deltaTime);
	double getTime();
public:
	Obj();
	~Obj();
};

