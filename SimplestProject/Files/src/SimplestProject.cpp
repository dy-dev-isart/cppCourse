// SimplestProject.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <sstream>

#include "raylibEncapsulate.h"
#include "demo/mesFonctions.h"


int main()
{
	//helloWorld();
	//getUserYearExperience();
	int speed = 0;// whatSpeed();
	//save as a string stream
	std::stringstream ss;
	ss << "You want to go at " << speed << " km/h.";
	demoRaylib(ss.str() );
	return 0;
}
