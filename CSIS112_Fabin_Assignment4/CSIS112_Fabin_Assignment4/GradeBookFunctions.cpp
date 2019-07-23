/*GradeBookFunctions.cpp -- containing the supporting functions for the main() function
 *CSIS 112-D01 LUO
 *No citations necessary
 */

#include "GradeBookFunctions.h"
#include "GradeBook.h"


void createGradeBook()
{
	std::cout << "Enter the gradebook name: \n";
	std::string gN;
	std::cin >> gN;
	GradeBook book(gN);
	bool flag{ true };
	//TODO: figure out how to add a menu that repeatedly generates
		switch (menu())
		{
		case Quit:
			return;
		case List: 
			book.printStudents();  // print the number of students
			break;

		case Add:
			if (book.numStudents() <= 3) {  // check to make sure we have fewer than three students!
				std::string n;
				std::cout << "\nEnter a student name: ";
				std::cin >> n;
				book.addStudent(n);
			}
			else
			{
				std::cout << "\nToo many students in the list!\n";
			}
			break;
		}
}
Menu menu()
{
	char uInput;
	do
	{
		std::cout << "\nEnter Q to quit, L to list items, or A to add items: ";
		std::cin >> uInput;
	} while (uInput != 'Q' && uInput != 'L' && uInput != 'A');
	switch(uInput) {
	case 'Q': return Quit;
	case 'L': return List;
	case 'A': return Add;
	default :
		std::cout << "\nAn error occured!";
		return Quit;
	}
}

std::string enterName()
{
	//TODO: add logic for the cases
	std::string n;
	bool flag{ true };
	std::getline(std::cin, n);
	return n;
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