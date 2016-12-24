/*
 * DirectoryIteration.hpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_DIRECTORYITERATION_HPP_
#define CODE_DIRECTORYITERATION_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

#include "FileParsing.hpp"

typedef boost::filesystem::recursive_directory_iterator iterator;

namespace Input
{

class DirectoryIteration
{
public:

	DirectoryIteration();
	virtual ~DirectoryIteration();
	void iterateDirectories();
private:
	boost::filesystem::path location;
	std::set<std::string> matfiles;
	FileParsing file;
};

} /* namespace Iteration */

#endif /* CODE_DIRECTORYITERATION_HPP_ */
