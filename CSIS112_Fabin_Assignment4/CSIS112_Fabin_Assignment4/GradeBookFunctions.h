/*GradeBookFunctions.h -- containing the header definitions for the main() function's supporting functions
 *CSIS 112-D01 LUO
 *No citations necessary
 */


#pragma once
#ifndef GRADEBOOKFUNCTIONS_H
#define GRADEBOOKFUNCTIONS_H
#include "Utilities.h"

// Type definitions
enum Menu {Add, List, Quit};

// Functions
void createGradeBook();
Menu menu();
std::string enterName();
void wait();
#endif