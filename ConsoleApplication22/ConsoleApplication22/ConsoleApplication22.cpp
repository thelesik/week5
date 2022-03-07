// ConsoleApplication22.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include "listfunctions.h"

int main()
{
    std::cout << "Hello World!\n";
}

/*Create a C++ program that will keep a list of books.  Your program must meet the following criteria:
The program will provide the user with a menu to add names to the list, delete a name from the list (searching by title), display the list in it's entirety
The list of books will be stored as a dynamically allocated array of strings.  The strings can be either STL strings or C style strings
The list must be stored in a class
There must be an operator overload created for the stream extraction operator that will handle the output of the list
You must provide a copy constructor for the class that will allow the programmer to set one class object equal to another
There must be a function to allow the list size to be increased without losing data that has been previously stored in the list.*/