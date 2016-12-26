/*
 * DirectoryIteration.hpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_COLLECTOR_HPP_
#define CODE_COLLECTOR_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <set>

typedef boost::filesystem::recursive_directory_iterator iterator;

namespace Input
{

class Collector
{
public:
	Collector();
	virtual ~Collector();
	const std::set<boost::filesystem::path> iterateDirectories();
	const std::set<boost::filesystem::path> parseFile(boost::filesystem::path location);
private:
	std::set<boost::filesystem::path> matFiles;
};

} /* namespace Iteration */

#endif /* CODE_COLLECTOR_HPP_ */
