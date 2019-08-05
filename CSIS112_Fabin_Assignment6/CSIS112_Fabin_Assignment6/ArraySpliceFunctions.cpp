/*ArraySpliceFunctions.cpp -- Contains the functions used for the Array Splice program
 *CSIS 112-D01 LUO
 * REF:
 * 1: confirming the need to return a pointer to int rather than array https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions
 * 2: creating arrays dynamically https://stackoverflow.com/questions/28625465/c-creating-an-array-with-a-size-entered-by-the-user
 */

#include "ArraySpliceFunctions.h"
#include <cassert>

int * createArray(const int size)// REF 1 TODO: build array generation using srand and then return the array
{
	int *i = new int[size]; // REF 2

	srand(100);
	for (int loc = 0; loc < size; loc++)
	{
		i[loc] = rand();
		std::cout << loc << ": " << i[loc] << std::endl;
	}
	std::cout << "\n Array Printed \n";
	return i;
}

int getArraySize(const int arrayNum)
{
	std::cout << "Please enter the size of array " << arrayNum << ": ";
	int size;
	while (!(std::cin >> size) || size < 0) //TODO: fix issue with entering anything other than a number
	{
		std::cout << "\nPlease enter the size of array " << arrayNum << ": ";
		std::cin >> size;
	}
		
	return size;
}

void deleteArrays(int *a, int *b, int *c)
{
	delete[] a;
	delete[] b;
	delete[] c;  // TODO: Fix thrown exception
}

int * splice(int *a, int *b, const int aSize, const int bSize, const int initSz)
{
	// Set important size
	int cSize{ aSize + bSize};
	const int szAftrCpy{ initSz + bSize };
	std::cout << "\ncSize = " << cSize;
	std::cout << "\nszAftrCpy = " << szAftrCpy << std::endl;

	// Set up new array
	int *c = new int[aSize + bSize]; // REF 2

	if (initSz > 0)
	{
		for (int x{ 0 }; x < initSz; x++)
		{
			*(c) = *(a);
			std::cout << "\nx1 = " << x << " c = " << *c << " a = " << *a << std::endl;
			c++;
			a++;
		}
	}
	for (int x{ initSz }; x < szAftrCpy; x++)
	{
		*(c) = *(b);
		std::cout << "\nx2 = " << x << " c = " << *c << " a = " << *a << std::endl;
		*c++;
		*b++;
	}
	for (int x{ szAftrCpy }; x < cSize; x++) //TODO: FIX ACCESS VIOLATION FOR CSIZE = INITSZE
	{
		*(c) = *(a);
		std::cout << "\nx2 = " << x << " c = " << *c << " a = " << *a << std::endl;
		*c++;
		*a++;
	}
	int flag{ 0 };
	*c--;
	for (int x{ 0 }; x < cSize; x++)
		*c--;
	std::cout << "\nReturning C\n";
	return c;
}


// FUNCTIONS DEFINED IN UTILITIES_H:

void arraySplice()
{
	// Get the size of each array from the user
	const int a1_size{ getArraySize(1) };
	const int a2_size{ getArraySize(2) };
	const int a3_size{ a1_size + a2_size };  // for the third array, it will be the size of the other two arrays
	//TODO: CHECK THE SIZE CONSTRAINTS TO MAKE SURE THAT ARRAYS ARE THE CORRECT SIZE

	// Create the main two arrays
	int *array1{ createArray(a1_size) };
	int *array2{ createArray(a2_size) };

	std::cout << "Enter the number of elements from array 1 to copy: ";
	int numToCpy;
	while (!(std::cin >> numToCpy) || numToCpy > a1_size || numToCpy < 0) //TODO: Check the parameters
		if (numToCpy > a1_size || numToCpy < 0)
			std::cout << "\nPlease enter a non-negative number less than the total number of elements in array 1: ";
		else
			std::cout << "\nEnter the number of elements from array 1 to copy: ";

	// Get the value of the third array from the splice() function
	int *array3{ splice(array1, array2, a1_size, a2_size, numToCpy) };

	std::cout << "Final array values:";
	
	std::cout << "\nArray 1: " << std::endl;
	for (int i{ 0 }; i < a1_size; i++)
	{
		if (((i + 1) % 10) == 0)
			std::cout << std::endl;
		std::cout << array1[i] << " ";
	}
	std::cout << "\nArray 2: " << std::endl;
	for (int i{ 0 }; i < a2_size; i++)
	{
		if (((i + 1) % 10) == 0)
			std::cout << std::endl;
		std::cout << array2[i] << " ";
	}
	std::cout << "\nArray 3: " << std::endl;
	for (int i{ 1 }; i <= a3_size; i++)
	{
		if (((i + 1) % 10) == 0)
			std::cout << std::endl;
		std::cout << array3[i] << " ";
	}
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