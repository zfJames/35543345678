#pragma once
#include "Mammal.h"
class Dog :
	public Mammal
{
public:
	// Constructors
	Dog(std::string dName, int dWeight);
	// Destructors
	~Dog();
	// Functions
	void Speak() override;
};

