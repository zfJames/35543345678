/* ArraySpliceFunction.h -- Contains the functions not used in ArraySpliceDriver.cpp but used in ArraySpliceFunctions.cpp
 *CSIS 112-D01 LUO
 */

#pragma once
#include "Utilities.h"
int getArraySize();
int * createArray(const int size);
int * splice(int *a, int *b, const int aSize, const int bSize, const int initSz);
void printArrays(const int*array, const int arraySize);
void deleteArrays(int *a, int *b, int *c);

// followed in ArraySpliceFunctions.cpp by the functions defined in Utilities.h
