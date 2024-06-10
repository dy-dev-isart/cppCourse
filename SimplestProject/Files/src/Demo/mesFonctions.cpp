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

#include <chrono>
using namespace std::chrono;

void getAllPrimes(bool smart, int max)
{
	int count = 0;

	auto start = high_resolution_clock::now();
	if (!smart)
	{
		for (int i = 0; i < max; i++)
		{
			if (brutePrime(i))
			{
				//std::cout << i << " , ";
				count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < max; i++)
		{
			if (smartPrime(i))
			{
				//std::cout << i << " , ";
				count++;
			}
		}
	}
	auto stop = high_resolution_clock::now();
	std::cout << " There are " << count << " number between 0 and " << max << std::endl;

	long countTime = 0;
	std::string unit = "seconds";
	if (!smart)
	{
		auto duration = duration_cast<seconds>(stop - start);
		countTime = duration.count();
	}
	else
	{
		auto duration = duration_cast<milliseconds>(stop - start);
		countTime = duration.count();
		unit = "microseconds";

	}
	std::cout << "it took " << countTime << " " <<unit << " to calculate " << max << std::endl;
}


bool brutePrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	bool isPrime = true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
		}
	}
	return isPrime;
}

bool smartPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	if (n == 2 || n == 3 || n == 5)
	{
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0)
	{
		return false;
	}
	for (int i = 5; i * i < n + 1; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}
