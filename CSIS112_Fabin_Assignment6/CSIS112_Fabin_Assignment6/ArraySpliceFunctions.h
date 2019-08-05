/* ArraySpliceFunction.h -- Contains the functions not used in ArraySpliceDriver.cpp but used in ArraySpliceFunctions.cpp
 *CSIS 112-D01 LUO
 */

#pragma once
#include "Utilities.h"
int * createArray(const int size);
int getArraySize(const int arrayNum);
void deleteArrays(int *a, int *b, int *c);
int * splice(int *a, int *b, const int aSize, const int bSize, const int initSz);
