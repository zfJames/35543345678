#pragma once
#include "Mammal.h"
class Pig :
	public Mammal
{
public:
	// Constructors
	Pig(std::string pName, int pWeight);
	// Destructors
	~Pig();
	// Functions
	void Speak() override;
};

