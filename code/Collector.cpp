/*
 * DirectoryIteration.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include "Collector.hpp"

#include <iostream>               // for std::cout

namespace Input
{

Collector::Collector() :
		location("C:\\Users\\nicov\\Documents\\AutomatApp\\test_data")
{
}

Collector::~Collector()
{
}

void Collector::iterateDirectories()
{
	for (auto it : boost::filesystem::recursive_directory_iterator(location))
	{
		//std::cout << it << std::endl;
		if (boost::filesystem::is_regular_file(it))        // is p a regular file?
		{
			std::cout << it << " size is " << boost::filesystem::file_size(it) << '\n';
			if (boost::filesystem::extension(it) == ".pmd")
			{
				std::cout << "PMD FOUND" << std::endl;
				std::set<boost::filesystem::path> temp = parseFile(it);
				matfiles.insert(temp.begin(),temp.end());
			}
		}
		else if (boost::filesystem::is_directory(it))      // is p a directory?
			std::cout << it << "is a directory\n";
		else
			std::cout << it << "exists, but is neither a regular file nor a directory\n";
	}

	std::cout<<"show the set"<<std::endl;
	for(boost::filesystem::path s: matfiles)
	{
		std::cout<<s.string()<<std::endl;
	}
}

const std::set<boost::filesystem::path> Collector::parseFile(boost::filesystem::path location)
{
	std::ifstream input(location.string(), std::ios::binary);
	std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

	/*
	 * Regex checks if for a match where the string starts with a '/' character,
	 * followed by any character except the 'null' character, ending with .mat.
	 */
	std::regex e("(\\/[^\\x00]*.mat)");
	std::smatch matchResult;
	std::set<boost::filesystem::path> s;

	auto words_begin = std::sregex_iterator(content.begin(), content.end(), e);
	auto words_end = std::sregex_iterator();
	for (std::sregex_iterator sri = words_begin; sri != words_end; ++sri)
	{
		std::smatch match = *sri;
		boost::filesystem::path match_str = match.str();

		s.insert(match_str);
		std::cout << match_str << std::endl;
	}

	return s;
}

} /* namespace Iteration */
