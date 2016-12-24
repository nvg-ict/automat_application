/*
 * FileParsing.cpp
 *
 *  Created on: 25 Dec 2016
 *      Author: Nico
 */

#include "FileParsing.hpp"

namespace Input
{

FileParsing::FileParsing()
{
	// TODO Auto-generated constructor stub

}

FileParsing::~FileParsing()
{
	// TODO Auto-generated destructor stub
}

const std::set<std::string> FileParsing::parseFile(boost::filesystem::path location)
{
	std::ifstream input(location.string(), std::ios::binary);
	std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

	std::regex e("(\\/[^\\x00]*.mat)");
	std::smatch matchResult;
	std::set<std::string> s;

	auto words_begin = std::sregex_iterator(content.begin(), content.end(), e);
	auto words_end = std::sregex_iterator();
	for (std::sregex_iterator sri = words_begin; sri != words_end; ++sri)
	{
		std::smatch match = *sri;
		std::string match_str = match.str();

		s.insert(match_str);
		std::cout << match_str << std::endl;
	}

	return s;
}

} /* namespace Input */

