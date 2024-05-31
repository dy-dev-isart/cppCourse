// SimplestProject.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <sstream>

#include "raylibEncapsulate.h"
#include "demo/mesFonctions.h"


void displayCharAsBitsArray(char c)
{
	for (int i = 0; i < 8; ++i)
	{
		if (c & (1 << i))
		{
			std::cout << "1";
		}
		else
		{
			std::cout << "0";
		}
	}
}

void createSaveChar()
{
	//Character runs left = 0, right = 1
	char leftRight = 1;

	//First sprite = 0, second = 1, third = 2
	char spriteNb = 2;

	//Nb lives left
	char lives = 3;

	//Up (0), middle (1) or down (2)
	char upMiddleDown = 2;

	unsigned char save = upMiddleDown << 6 | lives << 3 | spriteNb << 1 | leftRight;
	std::cout << "Save char: " << (int)save << std::endl;
}
void readSaveChar()
{
	unsigned char save = 157;
	int offset = 0;
	char leftRight = save & 1;
	offset += 1;
	char spriteNb = (save >> offset) & 3;// 3 => 0b11 (en binaire)
	offset += 2;
	char lives = (save >> offset) &7 ;// 7 => 0b0000_0111 (en binaire)
	offset += 3;
	char upMiddleDown = (save >> offset) & 3;// 3 => 0b11 (en binaire)
	std::cout << "LeftRight: " << (int)leftRight << std::endl;
}
int main()
{
	//helloWorld();
	//getUserYearExperience();
	int speed = 0;// whatSpeed();

	char a;
	std::cout << "Enter a character: ";
	std::cin >> a;
	std::cout << "The character " << a << "(" << (int)a << ")" << " is represented as: ";
	displayCharAsBitsArray(a);
	createSaveChar();
	readSaveChar();
	//save as a string stream
	//std::stringstream ss;
	//ss << "You want to go at " << speed << " km/h.";
	//demoRaylib(ss.str());
	return 0;
}
