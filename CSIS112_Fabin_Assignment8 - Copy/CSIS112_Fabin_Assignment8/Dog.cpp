#include "Dog.h"

// Constructors

Dog::Dog(std::string dName, int dWeight) : Mammal(dName, dWeight)
{
	std::cout << "Invoking Dog default constructor\n";
}

// Destructors

Dog::~Dog()
{
	std::cout << "Invoking Dog default destructor\n";
}

// Public Functions

void Speak()
{
	std::cout << "Woof\n";
}