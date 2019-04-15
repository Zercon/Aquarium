#include <iostream>

#include "Aquarium.h"

using namespace std;

int main()
{

	int height = 0, width = 0;
	int countFish, countCarnivorousFish, countPlankton;
	double lifetimeFish, lifetimeCarnivorousFish, lifetimePlankton;
	double timeSegmentationPlankton, saturationTimeFish, saturationTimeCarnivorousFish;
	double breedingTimeFish, breedingTimeCarnivorousFish;

	setlocale(0, "");

	cout << "        >>>>>>>>>>>>>>>>>>>>   AQUARIUM   <<<<<<<<<<<<<<<<<<<" << endl;
	cout << "Введите размеры аквариума(в пикселях)!" << endl 
		<< "Высота: ";
	cin >> height;
	cout << "Ширина: ";
	cin >> width;
	cout << "Количество травоядных рыбок: ";
	cin >> countFish;
	cout << "Количество хищных рыбок: ";
	cin >> countCarnivorousFish;
	cout << "Количество планктона: ";
	cin >> countPlankton;
	cout << "Время указываем в миллисекундах(1 сек == 1000 мс)!" << endl;
	cout << "Время жизни травоядных рыбок: ";
	cin >> lifetimeFish;
	cout << "Время жизни хищных рыбок: ";
	cin >> lifetimeCarnivorousFish;
	cout << "Время жизни планктона: ";
	cin >> lifetimePlankton;
	cout << "Время деления планктона: ";
	cin >> timeSegmentationPlankton;
	cout << "Время сытости травоядных рыбок: ";
	cin >> saturationTimeFish;
	cout << "Время сытости хищных рыбок: ";
	cin >> saturationTimeCarnivorousFish;
	cout << "Время размножения травоядных рыбок: ";
	cin >> breedingTimeFish;
	cout << "Время размножения хищных рыбок: ";
	cin >> breedingTimeCarnivorousFish;

	Aquarium aquarium(height, width, countFish, countCarnivorousFish, countPlankton,
		lifetimeFish, lifetimeCarnivorousFish, lifetimePlankton, timeSegmentationPlankton,
		saturationTimeFish, saturationTimeCarnivorousFish, breedingTimeFish, breedingTimeCarnivorousFish);

	aquarium.run();

	system("PAUSE");

	return 0;
}