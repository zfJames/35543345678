/*GradeBook.h -- containing tge GradeBook class definition
 *CSIS 112-D01 LUO
 *Reference wrapping = http://www.cplusplus.com/reference/functional/reference_wrapper/
 */

#pragma once
#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include "Utilities.h"
#include <vector>
#include <functional>
#include "Student.h"


class GradeBook
{
public:
	explicit GradeBook(std::string n);
	~GradeBook();

	void setGradeBookName(std::string n);
	std::string getGradeBookName();

	int numStudents();

	void addStudent(std::string sN);

	void printStudents();

private:
	std::string gradebookName;
	std::vector<Student> studentList; // set up a vector list
};

#endif