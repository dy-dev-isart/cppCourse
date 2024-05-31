#include <iostream>
#include "demo/mesFonctions.h"


void hello()
{
	std::cout << "Hello World!";
}

void luvingit()
{
	std::cout << "Learning C++ and I'm luving it!" << std::endl;
}

void getUserYearExperience()
{
	int yearExperience;
	std::cout << "How many years of experience do you have in programming? ";
	std::cin >> yearExperience;
	std::cout << "You have " << yearExperience << " years of experience in programming." << std::endl;
}

void helloWorld()
{
	hello();
	std::cout << ' ';
	luvingit();
}

int whatSpeed()
{
	int speed;
	std::cout << "What speed do you want to go? ";
	std::cin >> speed;
	return speed;
}
