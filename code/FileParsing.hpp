/*
 * FileParsing.hpp
 *
 *  Created on: 25 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_FILEPARSING_HPP_
#define CODE_FILEPARSING_HPP_

#include <string>
#include <set>
#include <iostream>               // for std::cout
#include <regex>
#include <fstream>
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

namespace Input
{

class FileParsing
{
public:
	FileParsing();
	virtual ~FileParsing();
	const std::set<std::string> parseFile(boost::filesystem::path location);
private:
};

} /* namespace Input */

#endif /* CODE_FILEPARSING_HPP_ */
