#pragma once
#include "Utilities.h"
class Mammal
{
public:
	// Constructors
	Mammal();
	Mammal(std::string mName, float mWeight);
	// Destructors
	~Mammal();
	// Getters
	float getWeight() const;
	std::string getName() const;
	// Setters
	void setWeight(const float iWeight);
	void setName(const std::string iName);
	// Functions
	virtual void Speak();  // not implemented [for some reason, setting this equal to 0 (virtual void Speak() = 0;) throws an error on line 12 of Driver.cpp
private:
	// Variables
	float weight;
	std::string name;
};

