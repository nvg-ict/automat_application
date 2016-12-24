/*
 * main.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include <iostream>               // for std::cout
#include "DirectoryIteration.hpp"
#include <regex>
#include <string>
#include <set>

int main(int argc, char **argv)
{
	try {

		std::cout << "Program has started" << std::endl;
		Input::DirectoryIteration d;
		d.iterateDirectories();



		return 0;
	} catch (std::exception& e) {
		std::cout <<e.what() << std::endl;
	}

}

