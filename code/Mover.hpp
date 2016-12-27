/*
 * Mover.hpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_MOVER_HPP_
#define CODE_MOVER_HPP_

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

namespace Copy
{

class Mover
{
public:
	Mover(boost::filesystem::path anExport);
	virtual ~Mover();
	bool copyFile(boost::filesystem::path path);
private:
	bool checkIfMatPresent(boost::filesystem::path path);
	boost::filesystem::path createRootPath(const boost::filesystem::path& path);
	boost::filesystem::path createNewLocationPath(const boost::filesystem::path& path);
	boost::filesystem::path createExportDirectory(const boost::filesystem::path& path);
	const boost::filesystem::path exportDirectory;
};

} /* namespace Copy */

#endif /* CODE_MOVER_HPP_ */
