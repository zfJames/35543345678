/*GradeBookDriver.cpp -- containing the main() function
 *CSIS 112-D01 LUO
 *No citations necessary
 */

#include "Utilities.h"
#include "GradeBookFunctions.h"

int main(int argc, char* argv[])
{

	std::cout << "Zach Fabin - Assignment 4\n";  // outputting name
	createGradeBook(); // creating a gradebook and passing off control
	wait(); // receiving control back and waiting for the user input....
	return 0;
}
