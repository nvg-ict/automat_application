/*
 * DirectoryIteration.hpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_DIRECTORYITERATION_HPP_
#define CODE_DIRECTORYITERATION_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

namespace Iteration
{

class DirectoryIteration
{
public:

	DirectoryIteration();
	virtual ~DirectoryIteration();
	void iterateDirectories();
private:
	struct recursive_directory_range
		{
			typedef boost::filesystem::recursive_directory_iterator iterator;
			recursive_directory_range(boost::filesystem::path aP) :
					p(aP)
			{
			}

			iterator begin()
			{
				return boost::filesystem::recursive_directory_iterator(p);
			}
			iterator end()
			{
				return boost::filesystem::recursive_directory_iterator();
			}

			boost::filesystem::path p;
		};
	boost::filesystem::path location;
};

} /* namespace Iteration */

#endif /* CODE_DIRECTORYITERATION_HPP_ */
