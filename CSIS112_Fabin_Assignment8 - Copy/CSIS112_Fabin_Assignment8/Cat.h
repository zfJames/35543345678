#pragma once
#include "Mammal.h"
class Cat :
	public Mammal
{
public:
	// Constructors
	Cat(std::string cName, int cWeight);
	// Destructors
	~Cat();
	// Functions
	void Speak() override; // thought that maybe adding override would help, but nope...
};

