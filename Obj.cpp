#include "Obj.h"



Obj::Obj()
{
	setTime(0);
	this->sx = 0.0;
	this->sy = 0.0;
}

void Obj::setPosition(double x, double y) {
	this->x = x;
	this->y = y;
}

void Obj::setLifetime(double lifetime) {
	this->lifetime = lifetime;
}

double Obj::getLifetime() {
	return this->lifetime;
}

void Obj::setReproduces(int reproduces) {
	this->reproduces = reproduces;
}

int Obj::getReproduced() {
	return this->reproduces;
}

void Obj::setGender(int gender) {
	this->gender = gender;
}

int Obj::getGender() {
	return this->gender;
}

void Obj::setTime(double time) {
	this->time = time;
}

void Obj::incrementTime(double deltaTime) {
	this->time += deltaTime;
}

double Obj::getTime() {
	return this->time;
}

Obj::~Obj()
{
}
