#include "Aquarium.h"

#include <iostream>
#include <random>
#include <ctime>
#include <set>

#include "Obj.h"
#include "Fish.h"
#include "CarnivorousFish.h"
#include "Plankton.h"


#include <SFML/Graphics.hpp>

#define SPEEDFISH 30

Aquarium::Aquarium(int height, int width, int countFish, int countCarnivorousFish, int countPlankton,
	double lifetimeFish, double lifetimeCarnivorousFish, double lifetimePlankton,
	double timeSegmentationPlankton, double saturationTimeFish,
	double saturationTimeCarnivorousFish, double breedingTimeFish, double breedingTimeCarnivorousFish)
{
	this->height = height;
	this->width = width;
	this->countFish = countFish;
	this->countCarnivorousFish = countCarnivorousFish;
	this->countPlankton = countPlankton;
	this->lifetimeFish = lifetimeFish;
	this->lifetimeCarnivorousFish = lifetimeCarnivorousFish;
	this->lifetimePlankton = lifetimePlankton;
	this->timeSegmentationPlankton = timeSegmentationPlankton;
	this->saturationTimeFish = saturationTimeFish;
	this->saturationTimeCarnivorousFish = saturationTimeCarnivorousFish;
	this->breedingTimeFish = breedingTimeFish;
	this->breedingTimeCarnivorousFish = breedingTimeCarnivorousFish;

	this->lastTime = 0.0;
}

Plankton* Aquarium::closestPointPlankton(double x, double y) {
	double distance = 0.0;

	Plankton *lastPlankton = NULL;

	for (auto iter : allPlankton) {
		if (lastPlankton == NULL) {
			lastPlankton = iter;
			distance = sqrt(pow(lastPlankton->x - x, 2) + pow(lastPlankton->y - y, 2));
		}
		else {
			double newDistance = sqrt(pow(iter->x - x, 2) + pow(iter->y - y, 2));
			if (distance > newDistance){
				lastPlankton = iter;
				distance = newDistance;
			}
		}
	}

	return lastPlankton;
}

Fish* Aquarium::closestPointFish(double x, double y, int gender) {
	double distance = 0.0;

	Fish *lastFish = NULL;

	for (auto iter : allFish) {
		if (lastFish == NULL) {
			if ((gender == NO_GENDER) || (gender == iter->getGender())) {
				lastFish = iter;
				distance = sqrt(pow(lastFish->x - x, 2) + pow(lastFish->y - y, 2));
			}
		}
		else {
			if ((gender == NO_GENDER) || (gender == iter->getGender())) {
				double newDistance = sqrt(pow(iter->x - x, 2) + pow(iter->y - y, 2));
				if (distance > newDistance) {
					lastFish = iter;
					distance = newDistance;
				}
			}
		}
	}

	return lastFish;
}

CarnivorousFish* Aquarium::closestPointCarnivorousFish(double x, double y, int gender) {
	double distance = 0.0;

	CarnivorousFish *lastCarnivorousFish = NULL;

	for (auto iter : allCarnivorousFish) {
		if (lastCarnivorousFish == NULL) {
			if ((gender == NO_GENDER) || (gender == iter->getGender())) {
				lastCarnivorousFish = iter;
				distance = sqrt(pow(lastCarnivorousFish->x - x, 2) + pow(lastCarnivorousFish->y - y, 2));
			}
		}
		else {
			if ((gender == NO_GENDER) || (gender == iter->getGender())) {
				double newDistance = sqrt(pow(iter->x - x, 2) + pow(iter->y - y, 2));
				if (distance > newDistance) {
					lastCarnivorousFish = iter;
					distance = newDistance;
				}
			}
		}
	}

	return lastCarnivorousFish;
}

void Aquarium::genVector(Obj *obj) {
	double fi = 2 * 3.14 * (rand() % 360) / 360.0;

	obj->sx = SPEEDFISH * cos(fi);
	obj->sy = SPEEDFISH * sin(fi);
}

void Aquarium::run() {
	window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "AQUARIUM");

	for (int i = 0; i < countPlankton; i++) {
		Plankton *buffer = new Plankton(lifetimePlankton, timeSegmentationPlankton);
		buffer->setPosition(double(rand() % int(width)), double(rand() % int(height)));
		allPlankton.emplace(buffer);

	}

	for (int i = 0; i < countFish; i++) {
		Fish *buffer;
		if (i < int(countFish / 2.0))
			buffer = new Fish(lifetimeFish, MALE, saturationTimeFish, breedingTimeFish);
		else
			buffer = new Fish(lifetimeFish, FEMALE, saturationTimeFish, breedingTimeFish);
		genVector(buffer);
		buffer->setPosition(double(rand() % int(width)), double(rand() % int(height)));
		allFish.emplace(buffer);
	}

	for (int i = 0; i < countCarnivorousFish; i++) {
		CarnivorousFish *buffer;
		if (i < int(countFish / 2.0))
			buffer = new CarnivorousFish(lifetimeFish, MALE, saturationTimeCarnivorousFish, breedingTimeCarnivorousFish);
		else
			buffer = new CarnivorousFish(lifetimeFish, FEMALE, saturationTimeCarnivorousFish, breedingTimeCarnivorousFish);
		genVector(buffer);
		buffer->setPosition(double(rand() % int(width)), double(rand() % int(height)));
		allCarnivorousFish.emplace(buffer);
	}

	sf::CircleShape shapePlankton(3.f);
	shapePlankton.setFillColor(sf::Color::Green);

	sf::CircleShape shapeFish(10.f);
	shapeFish.setFillColor(sf::Color::Yellow);

	sf::RectangleShape shapeCarnivorousFish(sf::Vector2f(20, 20));
	shapeCarnivorousFish.setFillColor(sf::Color::Red);

	this->lastTime = clock();

	this->startTime = clock();

	while (window->isOpen())
	{

		if (allPlankton.empty() && allFish.empty() && allCarnivorousFish.empty())
			window->close();

		///////////////////////////////////

		unsigned int lastTime = clock();
		int deltaTime = int(lastTime - this->lastTime);
		this->lastTime = lastTime;

		std::set<Plankton*> eraseAllPlankton;
		std::set<Plankton*> emplaceAllPlankton;

		//планктон
		for (auto iter : allPlankton) {
			iter->incrementTime(deltaTime);
			if (iter->getTime() > iter->getLifetime()) {
				eraseAllPlankton.emplace(iter);
			}
			else {
				if (iter->timeSegmentation < iter->countdownTimeSegmentation) {
					iter->countdownTimeSegmentation = 0.0;
					double fi = 3.14 * (rand() % 360) / 180.0;
					Plankton *addBuffer = new Plankton(lifetimePlankton, timeSegmentationPlankton);
					addBuffer->setPosition(iter->x + 6 * cos(fi), iter->y + 6 * sin(fi));
					emplaceAllPlankton.emplace(addBuffer);
				}
			}
		}

		for (auto iter : eraseAllPlankton)
			allPlankton.erase(iter);

		for (auto iter : emplaceAllPlankton)
			allPlankton.emplace(iter);

		std::set<Fish*> eraseAllFish;
		std::set<Fish*> emplaceAllFish;

		//движение травоядных рыбок
		for (auto iter : allFish) {
			iter->incrementTime(deltaTime);
			iter->x += iter->sx * (deltaTime / 1000.0);
			iter->y += iter->sy * (deltaTime / 1000.0);
			if (iter->x < 0 || iter->x > width)
				iter->sx *= -1;
			if (iter->y < 0 || iter->y > height)
				iter->sy *= -1;

			if (((iter->getSaturationTime() * 3) < iter->countdownSaturationTime) ||
				(iter->getTime() > iter->getLifetime())) {
				eraseAllFish.emplace(iter);
			}
			else {
				if (iter->getSaturationTime() < iter->countdownSaturationTime) {
					Plankton *plankton = closestPointPlankton(iter->x, iter->y);
					if (plankton != NULL) {
						double dis = sqrt(pow(iter->y - plankton->y, 2) + pow(iter->x - plankton->x, 2));
						iter->sx = SPEEDFISH * (plankton->x - iter->x) / dis;
						iter->sy = SPEEDFISH * (plankton->y - iter->y) / dis;

						if (int(dis) < 10) {
							iter->countdownSaturationTime = 0;
							allPlankton.erase(plankton);
						}
					}
				}
				else {
					if (iter->getBreedingTime() < iter->countdownBreedingTime) {
						Fish *fish = NULL;
						if (iter->getGender() == MALE)
							fish = closestPointFish(iter->x, iter->y, FEMALE);
						if (iter->getGender() == FEMALE)
							fish = closestPointFish(iter->x, iter->y, MALE);
						if (fish != NULL) {
							double dis = sqrt(pow(iter->y - fish->y, 2) + pow(iter->x - fish->x, 2));
							iter->sx = SPEEDFISH * (fish->x - iter->x) / dis;
							iter->sy = SPEEDFISH * (fish->y - iter->y) / dis;

							if (int(dis) < 10) {
								if (fish->getBreedingTime() < fish->countdownBreedingTime) {
									fish->countdownBreedingTime = 0.0;
									iter->countdownBreedingTime = 0.0;

									Fish *addBuffer;
									if ((rand() % 2) == 1)
										addBuffer = new Fish(lifetimeFish, MALE, saturationTimeFish, breedingTimeFish);
									else
										addBuffer = new Fish(lifetimeFish, FEMALE, saturationTimeFish, breedingTimeFish);
									addBuffer->setPosition((fish->x + iter->x) / 2.0, (fish->y + iter->y) / 2.0);
									emplaceAllFish.emplace(addBuffer);
								}
							}
						}
					}
				}
			}
		}

		for (auto iter : eraseAllFish)
			allFish.erase(iter);

		for (auto iter : emplaceAllFish)
			allFish.emplace(iter);

		std::set<CarnivorousFish*> eraseAllCarnivorousFish;
		std::set<CarnivorousFish*> emplaceAllCarnivorousFish;

		//движение хищных рыбок
		for (auto iter : allCarnivorousFish) {
			iter->incrementTime(deltaTime);
			iter->x += iter->sx * (deltaTime / 1000.0);
			iter->y += iter->sy * (deltaTime / 1000.0);
			if (iter->x < 0 || iter->x > width)
				iter->sx *= -1;
			if (iter->y < 0 || iter->y > height)
				iter->sy *= -1;

			if ((iter->getSaturationTime() * 3) < iter->countdownSaturationTime ||
				(iter->getTime() > iter->getLifetime())) {
				eraseAllCarnivorousFish.emplace(iter);
			}
			else {
				if (iter->getSaturationTime() < iter->countdownSaturationTime) {
					Fish *fish = closestPointFish(iter->x, iter->y);
					if (fish != NULL) {
						double dis = sqrt(pow(iter->y - fish->y, 2) + pow(iter->x - fish->x, 2));
						iter->sx = SPEEDFISH * (fish->x - iter->x) / dis;
						iter->sy = SPEEDFISH * (fish->y - iter->y) / dis;

						if (int(dis) < 10) {
							iter->countdownSaturationTime = 0;
							allFish.erase(fish);
						}

					}
				}
				else {
					if (iter->getBreedingTime() < iter->countdownBreedingTime) {
						CarnivorousFish *carnivorousFish = NULL;
						if (iter->getGender() == MALE)
							carnivorousFish = closestPointCarnivorousFish(iter->x, iter->y, FEMALE);
						if (iter->getGender() == FEMALE)
							carnivorousFish = closestPointCarnivorousFish(iter->x, iter->y, MALE);
						if (carnivorousFish != NULL) {
							double dis = sqrt(pow(iter->y - carnivorousFish->y, 2) + pow(iter->x - carnivorousFish->x, 2));
							iter->sx = SPEEDFISH * (carnivorousFish->x - iter->x) / dis;
							iter->sy = SPEEDFISH * (carnivorousFish->y - iter->y) / dis;

							if (int(dis) < 10) {
								if (carnivorousFish->getBreedingTime() < carnivorousFish->countdownBreedingTime) {
									carnivorousFish->countdownBreedingTime = 0.0;
									iter->countdownBreedingTime = 0.0;

									CarnivorousFish *addBuffer;
									if ((rand() % 2) == 1)
										addBuffer = new CarnivorousFish(lifetimeFish, MALE, saturationTimeFish, breedingTimeFish);
									else
										addBuffer = new CarnivorousFish(lifetimeFish, FEMALE, saturationTimeFish, breedingTimeFish);
									addBuffer->setPosition((carnivorousFish->x + iter->x) / 2.0, (carnivorousFish->y + iter->y) / 2.0);
									emplaceAllCarnivorousFish.emplace(addBuffer);
								}
							}
						}
					}
				}
			}
		}

		for (auto iter : eraseAllCarnivorousFish)
			allCarnivorousFish.erase(iter);
		for (auto iter : emplaceAllCarnivorousFish)
			allCarnivorousFish.emplace(iter);

		///////////////////////////////////

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		
		//
		for (auto iter : allPlankton) {
			shapePlankton.setPosition(iter->x, iter->y);
			window->draw(shapePlankton);
		}

		for (auto iter : allFish) {
			shapeFish.setPosition(iter->x, iter->y);
			window->draw(shapeFish);
		}

		for (auto iter : allCarnivorousFish) {
			shapeCarnivorousFish.setPosition(iter->x, iter->y);
			window->draw(shapeCarnivorousFish);
		}
		//

		window->display();
		sf::sleep(sf::milliseconds(25));
	}

	this->endTime = clock();

	std::cout << "Время жизни аквариума: " << (this->endTime - this->startTime) / 1000.0 << " секунд" << std::endl;
}


Aquarium::~Aquarium()
{
}
