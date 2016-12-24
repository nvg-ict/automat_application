/*
 * main.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include <iostream>
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <iostream>               // for std::cout
//using namespace boost::filesystem;          // for ease of tutorial presentation;
                                  //  a namespace alias is preferred practice in real code

struct recursive_directory_range
{
    typedef boost::filesystem::recursive_directory_iterator iterator;
    recursive_directory_range(boost::filesystem::path p) : p_(p) {}

    iterator begin() { return boost::filesystem::recursive_directory_iterator(p_); }
    iterator end() { return boost::filesystem::recursive_directory_iterator(); }

    boost::filesystem::path p_;
};


int main(int argc, char **argv) {
	std::cout<<"Program has started"<<std::endl;
	for (auto it : recursive_directory_range("C:\\Users\\nicov\\Documents\\AutomatApp\\test_data"))
	{
	    std::cout << it << std::endl;
	}
	return 0;
}


