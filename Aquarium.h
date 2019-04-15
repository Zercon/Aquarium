#pragma once

#include <random>
#include <set>

#include "Obj.h"
#include "Fish.h"
#include "CarnivorousFish.h"
#include "Plankton.h"

#include <SFML/Graphics.hpp>

class Aquarium
{
private:
	int height = 0, width = 0;
	int countFish, countCarnivorousFish, countPlankton;
	double lifetimeFish, lifetimeCarnivorousFish, lifetimePlankton;
	double timeSegmentationPlankton, saturationTimeFish, saturationTimeCarnivorousFish;
	double breedingTimeFish, breedingTimeCarnivorousFish;

	unsigned int lastTime;
	unsigned int startTime, endTime;

	std::set<Plankton*> allPlankton;
	std::set<Fish*> allFish;
	std::set<CarnivorousFish*> allCarnivorousFish;

	sf::RenderWindow *window;
public:
	Aquarium(int height, int width, int countFish, int countCarnivorousFish, int countPlankton,
		double lifetimeFish, double lifetimeCarnivorousFish, double lifetimePlankton, 
		double timeSegmentationPlankton, double saturationTimeFish,
		double saturationTimeCarnivorousFish, double breedingTimeFish, double breedingTimeCarnivorousFish);

	Plankton* closestPointPlankton(double x, double y);
	Fish* closestPointFish(double x, double y, int gender = NO_GENDER);
	CarnivorousFish* closestPointCarnivorousFish(double x, double y, int gender);
	void genVector(Obj *obj);

	void run();
	~Aquarium();
};

