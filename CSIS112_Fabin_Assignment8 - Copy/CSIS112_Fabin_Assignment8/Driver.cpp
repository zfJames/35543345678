/*Driver.cpp -- containing the main function and all of the supporting functions
 *CSIS 112-D01 LUO
 * STL's integer distribution: https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
 */

#include "Driver.h"



int main(int argc, char* argv[])
{
	Mammal* animals[5];
	std::mt19937 mt(100);  // using the random integer distribution suggested by STL
	int animal{ 0 };
	for (int x{ 0 }; x < 5; x++) {
		std::uniform_int_distribution<int> dist(0, 150);
		std::cout << dist(mt) << std::endl << dist(mt) << std::endl << dist(mt) << std::endl;
		std::cout << "Enter the name of an animal: ";
		while (!(std::cin >> animal) || animal != 1 && animal != 2 && animal != 3 && animal != 4)
		{
			std::cout << "Enter the name of an animal: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//std::cin >> animal;
		}
		switch (animal)
		{
		case 1: std::cout << "\nYou entered a dog!";
			animals[x] = new Dog(returnName(), dist(mt));
			break;
		case 2: std::cout << "\nYou entered a cat!";
			animals[x] = new Cat(returnName(), dist(mt));
			break;
		case 3: std::cout << "\nYou entered a horse!";
			animals[x] = new Horse(returnName(), dist(mt));
			break;
		case 4: std::cout << "\nYou entered a pig!";
			animals[x] = new Pig(returnName(), dist(mt));
			break;
		default: std::cout << "\nWhoops!  Don't know how you got here!";
			wait();
			return 0;
		}
	}
	for (int x{ 0 }; x < 5; x++)
	{
		std::string name = animals[x]->getName();
		int weight = animals[x]->getWeight();
		std::cout << "Animal Name: " << name << std::endl << "Animal Weight: " << weight << std::endl;
		animals[x]->Speak();
		delete[] animals[x]; // delete each animal after we are done with them
	}
	wait();
	return 0;
}

std::string returnName()
{
	std::cout << "\nPlease enter the name of an animal: ";
	std::string name;
	std::getline(std::cin, name);  // get a line that has the name of the function
	return name;
}

void wait()   //Causes the program to pause until the user presses the Enter key
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (std::cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		std::cin.clear();
		std::cin.ignore(); //Clear the input buffer 
	}
	char ch;
	std::cout << "Press the Enter key to continue ... ";
	std::cin.get(ch);
}