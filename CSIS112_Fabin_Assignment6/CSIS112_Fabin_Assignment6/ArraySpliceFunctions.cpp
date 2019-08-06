/*ArraySpliceFunctions.cpp -- Contains the functions used for the Array Splice program
 *CSIS 112-D01 LUO
 * REF (only applies to the lines specifically referenced):
 * 1: confirming the need to return a pointer to int rather than array https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions
 * 2: creating arrays dynamically https://stackoverflow.com/questions/28625465/c-creating-an-array-with-a-size-entered-by-the-user
 */

#include "ArraySpliceFunctions.h"

int getArraySize()
{
	static int arrayNum{ 1 };
	std::cout << "Please enter the size of array " << arrayNum << ": ";
	int size;
	while (!(std::cin >> size) || size < 0)
	{
		std::cout << "\nPlease enter the size of array " << arrayNum << ": ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // (from Dr. Poole) - correctly clearing the buffers as well as using the cin.clear function...
	}
	arrayNum++;
	return size;
}

int * createArray(const int size)// REF 1
{
	int *i = new int[size]; // REF 2

	srand(100); // seed the random number generator with a non-random seed //TODO: fix repetitive values by using system time (can one use a GUID?) *not part of the assignment instructions*
	for (int loc = 0; loc < size; loc++)  // for each spot in the array, put in a random number
		i[loc] = rand();
	return i;
}

int * splice(int *a, int *b, const int aSize, const int bSize, const int initSz)
{
	// Set important size
	int cSize{ aSize + bSize };
	const int szAftrCpy{ initSz + bSize };

	// Set up new array
	int *c = new int[aSize + bSize]; // REF 2


	if (initSz > 0)  // if the user actually wants to insert variables at the beginning
	{
		for (int x{ 0 }; x < initSz; x++)  // loop through the values of the first array that the user wants inserted
		{
			*(c) = *(a);  // update the pointer value
			*c++; *a++;
		}
	}
	for (int x{ initSz }; x < szAftrCpy; x++)  // put in the second array values
	{
		*(c) = *(b);  // update the pointer value
		*c++; *b++;
	}
	for (int x{ szAftrCpy }; x < cSize; x++)  // add in the remainder of the first array values
	{
		*(c) = *(a);  // update the pointer value
		*c++; *a++;
	}
	for (int x{ 0 }; x < cSize; x++) // reset the pointer position
		*c--;
	return c;
}

void printArrays(const int*array, const int arraySize)
{
	// Print out the array name:
	static int numArray{ 1 };
	std::cout << "\nArray " << numArray <<":" << std::endl;

	// Print out the array values
	for (int i{ 0 }; i < arraySize; i++)
	{
		if (((i) % 10) == 0)  // print a new line if the line is about to exceed ten entries
			std::cout << std::endl;
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	numArray++;
}

void deleteArrays(int *a, int *b, int *c)
{
	// Delete arrays
	delete[] a;
	delete[] b;
	delete[] c;
}


// FUNCTIONS DEFINED IN UTILITIES_H:


void arraySplice()
{
	// Get the size of each array from the user
	const int a1_size{ getArraySize() };
	const int a2_size{ getArraySize() };
	const int a3_size{ a1_size + a2_size };  // for the third array, it will be the size of the other two arrays

	// Create the main two arrays
	int *array1{ createArray(a1_size) };
	int *array2{ createArray(a2_size) };

	// getting user input
	std::cout << "Enter the number of elements from array 1 to copy: ";
	int numToCpy;
	while (!(std::cin >> numToCpy) || numToCpy > a1_size || numToCpy < 0) {
		if (numToCpy > a1_size || numToCpy < 0)
			std::cout << "\nPlease enter a non-negative number less than the total number of elements in array 1: ";
		else
			std::cout << "\nEnter the number of elements from array 1 to copy: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // same information from Dr. Poole :)
	}

	// Get the value of the third array from the splice() function
	int *array3{ splice(array1, array2, a1_size, a2_size, numToCpy) };

	// Print out the final array values:
	std::cout << "\nFinal array values:\n";
	printArrays(array1, a1_size);
	printArrays(array2, a2_size);
	printArrays(array3, a3_size);
	std::cout << std::endl;

	// delete the arrays
	deleteArrays(array1,array2,array3);
	return;
}

void wait() //Causes the program to pause until the user presses the Enter key
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