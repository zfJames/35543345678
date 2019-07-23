/*Student.cpp -- containing the class for the Student objects
 *CSIS 112-D01 LUO
 *No citations necessary
 */


#include "Student.h"
#include "GradeBook.h"

Student::Student(std::string name) : name{ name } //TODO: check to see if gradebook should be in there...
{
	grades.fill(0);
	gradeLocator = 0;
}


void Student::enterGrade()
{
	while (gradeLocator < 5)  // ensure that five grades or fewer are entered
	{
		float g;
		std::cout << "\nPlease enter a grade percentage or enter -1 to exit: \n";
		while (!(std::cin >> g))
		{
			std::cout << "\nPlease enter a grade percentage or enter -1 to exit: \n";
		}
		if (g >= 0)
		{
			gradeLocator++;
			grades.at(gradeLocator) = g;
		}
		else if (g == -1)
			return;
		else
		std::cout << "Grade invalid!  Please try again." << std::endl;
	}
}

void Student::displayRecord()
{
	std::cout << "Student Name: " << name << std::endl;
	for(int x = 0; x <= gradeLocator; x++)
		std::cout << "Grade " << x << ": " << grades.at(x);
}

