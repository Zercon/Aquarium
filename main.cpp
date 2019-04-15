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
	cout << "������� ������� ���������(� ��������)!" << endl 
		<< "������: ";
	cin >> height;
	cout << "������: ";
	cin >> width;
	cout << "���������� ���������� �����: ";
	cin >> countFish;
	cout << "���������� ������ �����: ";
	cin >> countCarnivorousFish;
	cout << "���������� ���������: ";
	cin >> countPlankton;
	cout << "����� ��������� � �������������(1 ��� == 1000 ��)!" << endl;
	cout << "����� ����� ���������� �����: ";
	cin >> lifetimeFish;
	cout << "����� ����� ������ �����: ";
	cin >> lifetimeCarnivorousFish;
	cout << "����� ����� ���������: ";
	cin >> lifetimePlankton;
	cout << "����� ������� ���������: ";
	cin >> timeSegmentationPlankton;
	cout << "����� ������� ���������� �����: ";
	cin >> saturationTimeFish;
	cout << "����� ������� ������ �����: ";
	cin >> saturationTimeCarnivorousFish;
	cout << "����� ����������� ���������� �����: ";
	cin >> breedingTimeFish;
	cout << "����� ����������� ������ �����: ";
	cin >> breedingTimeCarnivorousFish;

	Aquarium aquarium(height, width, countFish, countCarnivorousFish, countPlankton,
		lifetimeFish, lifetimeCarnivorousFish, lifetimePlankton, timeSegmentationPlankton,
		saturationTimeFish, saturationTimeCarnivorousFish, breedingTimeFish, breedingTimeCarnivorousFish);

	aquarium.run();

	system("PAUSE");

	return 0;
}