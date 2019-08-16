#include "Cat.h"

// Constructors

Cat::Cat(std::string cName, int cWeight) : Mammal(cName, cWeight)
{
	std::cout << "Invoking Cat default constructor\n";
}

// Destructors

Cat::~Cat()
{
	std::cout << "Invoking Cat default destructor\n";
}

// Public Functions

void Speak()
{
	std::cout << "Meow\n";
}