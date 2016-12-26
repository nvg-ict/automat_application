/*
 * main.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include <iostream>               // for std::cout
#include <regex>
#include <string>
#include <set>
#include "Collector.hpp"
#include "Logger.hpp"

int main(int argc, char **argv)
{
	try {

		std::cout << "Program has started" << std::endl;
		Input::Collector c;
		c.iterateDirectories();


		Logger::Logger::getLogger().writeToLogOutput();
		return 0;
	} catch (std::exception& e) {
		std::cout <<e.what() << std::endl;
	}

}

