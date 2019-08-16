#include "Mammal.h"

// Constructors and Destructors

Mammal::Mammal()  // default constructor
{
	std::cout << "Invoking Mammal default constructor\n";
	// setting weight and name parameters to default values
	weight = 0;
	name = "";  //TODO: find the error in the equals symbol here
}

Mammal::Mammal(std::string mName, float mWeight)  // custom constructor with parameters
{
	std::cout << "Invoking Mammal non-default constructor\n";
	// setting weight and name parameters to user-entered values
	weight = mWeight;
	name = mName;
}


Mammal::~Mammal()
{
	std::cout << "Invoking Mammal default destructor\n";
}

// Getters

float Mammal::getWeight() const
{
	return weight;
}

std::string Mammal::getName() const
{
	return name;
}

// Setters

void Mammal::setWeight(const float iWeight)
{
	weight = iWeight;
}

void Mammal::setName(const std::string iName)
{
	name = iName;
}