#pragma once
#include "Mammal.h"
class Horse :
	public Mammal
{
public:
	// Constructors
	Horse(std::string hName, int hWeight);
	// Destructors
	~Horse();
	// Functions
	void Speak() override;
};

