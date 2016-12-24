/*
 * main.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include <iostream>               // for std::cout
#include "DirectoryIteration.hpp"



int main(int argc, char **argv)
{
	try {
		std::cout << "Program has started" << std::endl;
		Iteration::DirectoryIteration d;
		d.iterateDirectories();
		return 0;
	} catch (std::exception& e) {
		std::cout <<e.what() << std::endl;
	}

}

