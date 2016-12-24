/*
 * DirectoryIteration.hpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_DIRECTORYITERATION_HPP_
#define CODE_DIRECTORYITERATION_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

typedef boost::filesystem::recursive_directory_iterator iterator;

namespace Iteration
{

class DirectoryIteration
{
public:

	DirectoryIteration();
	virtual ~DirectoryIteration();
	void iterateDirectories();
private:
	boost::filesystem::path location;
};

} /* namespace Iteration */

#endif /* CODE_DIRECTORYITERATION_HPP_ */
