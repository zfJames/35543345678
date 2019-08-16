#include "Horse.h"

// Constructors

Horse::Horse(std::string hName, int hWeight) : Mammal(hName, hWeight)
{
	std::cout << "Invoking Horse default constructor\n";
}

// Destructors

Horse::~Horse()
{
	std::cout << "Invoking Horse default constructor\n";
}

// Public Functions

void Speak()
{
	std::cout << "I'm Mr. Ed\n";
}