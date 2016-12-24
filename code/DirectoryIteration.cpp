/*
 * DirectoryIteration.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include "DirectoryIteration.hpp"
#include <iostream>               // for std::cout

namespace Iteration
{

DirectoryIteration::DirectoryIteration() :
location("C:\\Users\\nicov\\Documents\\AutomatApp\\test_data")
{
}

DirectoryIteration::~DirectoryIteration()
{
}


void DirectoryIteration::iterateDirectories()
{
for (auto it : recursive_directory_range(location))
	{
		//std::cout << it << std::endl;

		if (boost::filesystem::is_regular_file(it))        // is p a regular file?
		{
			std::cout << it << " size is " << boost::filesystem::file_size(it) << '\n';
		if(boost::filesystem::extension(it) == ".pmd")
		{
			std::cout << "PMD FOUND" << std::endl;
		}
		}

		else if (boost::filesystem::is_directory (it))      // is p a directory?
			std::cout << it << "is a directory\n";

		else
			std::cout << it << "exists, but is neither a regular file nor a directory\n";
	}
}

} /* namespace Iteration */
