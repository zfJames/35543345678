/*GradeBook.cpp -- containing the class for the GradeBook objects
 *CSIS 112-D01 LUO
 *No citations necessary
 */



#include "GradeBook.h"

GradeBook::GradeBook(std::string n)
{
	setGradeBookName(n);
}


GradeBook::~GradeBook()
{ //default destructor not really necessary here, but included for clarity
}


void GradeBook::setGradeBookName(std::string n)
{
	gradebookName = n;
}

std::string GradeBook::getGradeBookName()
{
	return gradebookName;
}

int GradeBook::numStudents()
{
	return studentList.size();
}

void GradeBook::addStudent(std::string sN)
{
		Student student(sN);
		student.enterGrade(); // adding grades
		studentList.push_back(student);
}

void GradeBook::printStudents()
{
	for (Student student : studentList) // for each item in the list of students, display the studen trecord
		student.displayRecord();
}

