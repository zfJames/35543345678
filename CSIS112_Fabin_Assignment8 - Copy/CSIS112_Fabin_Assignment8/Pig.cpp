#include "Pig.h"

// Constructors

Pig::Pig(std::string pName, int pWeight) : Mammal(pName, pWeight)
{
	std::cout << "Invoking Pig default constructor\n";
}

// Destructors

Pig::~Pig()
{
	std::cout << "Invoking Pig default destructor\n";
}

// Public Functions

void Speak()
{
	std::cout << "Oink\n";
}