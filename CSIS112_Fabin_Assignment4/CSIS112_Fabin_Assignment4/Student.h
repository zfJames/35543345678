/*Student.h -- containing the class definition for the Student class
 *CSIS 112-D01 LUO
 *No citations necessary
 */

#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <array>
#include "GradeBook.h"

class Student : public GradeBook
{
public:
	Student(std::string name);
	~Student();
	void enterGrade();
	void displayRecord();
private:
	std::string name;
	std::array<float, 5> grades;
	int gradeLocator;
};

#endif