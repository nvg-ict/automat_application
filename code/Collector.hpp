/*
 * DirectoryIteration.hpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_COLLECTOR_HPP_
#define CODE_COLLECTOR_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

#include "FileParsing.hpp"

typedef boost::filesystem::recursive_directory_iterator iterator;

namespace Input
{

class Collector
{
public:

	Collector();
	virtual ~Collector();
	void iterateDirectories();
	const std::set<boost::filesystem::path> parseFile(boost::filesystem::path location);
private:
	boost::filesystem::path location;
	std::set<boost::filesystem::path> matfiles;
	//const std::set<boost::filesystem::path> parseFile(boost::filesystem::path location);
};

} /* namespace Iteration */

#endif /* CODE_COLLECTOR_HPP_ */
