/*
 *  Hello World header file
 *   Copyright 2018
 *
 *  Contributors:
 *   Aaron S. Crandall <acrandal@wsu.edu>
 */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>

/* Prints the Hello World string to a provided stream */
void print_hello_world(std::ostream& out)
{
    out << "Hello World!" << std::endl;
}

#endif
