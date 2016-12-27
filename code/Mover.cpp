/*
 * Mover.cpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#include "Mover.hpp"
#include "Logger.hpp"

#include <algorithm>
#include <iostream>

namespace Copy
{

Mover::Mover(boost::filesystem::path anExport) :
		exportDirectory(anExport)
{
}

Mover::~Mover()
{
}

bool Mover::checkIfMatPresent(boost::filesystem::path path)
{
	std::cout << path.string() << std::endl;
	return boost::filesystem::exists(path);
}

bool Mover::copyFile(boost::filesystem::path path)
{
	boost::filesystem::path root = createRootPath(path);
	boost::filesystem::path newLocation = createNewLocationPath(path);
	boost::filesystem::path createDirectory = createExportDirectory(path);

	std::cout << "Create path: " << createDirectory << std::endl;
	std::cout << "Root path: " << root << std::endl;
	std::cout << "New Location path: " << newLocation << std::endl;

	if (checkIfMatPresent(root))
	{
		boost::filesystem::create_directories(createDirectory.parent_path());
		try
		{
			boost::filesystem::copy_file(root, newLocation, boost::filesystem::copy_option::overwrite_if_exists);
			Logger::Logger::getLogger().log(std::string("Lets add some errors, because we can"),true);
			return true;
		} catch (const boost::filesystem::filesystem_error& ex)
		{
			Logger::Logger::getLogger().log(std::string(ex.what()),true);
			std::cout << ex.what() << '\n';
			return false;
		}
	}
	else
	{
		std::cout << "MAT not present" << std::endl;
		return false;
	}
}

boost::filesystem::path Mover::createNewLocationPath(const boost::filesystem::path& path ) {
	boost::filesystem::path newLocation = boost::filesystem::current_path();
	newLocation /= exportDirectory;
	newLocation /= path;
	std::string newLocationS = newLocation.string();
	std::replace(newLocationS.begin(), newLocationS.end(), '/', '\\'); // replace all 'x' to 'y'
	newLocation = newLocationS;

	return newLocation;
}

boost::filesystem::path Mover::createRootPath(const boost::filesystem::path& path ) {
	boost::filesystem::path root = boost::filesystem::current_path();
	root /= path;
	std::string rootS = root.string();
	std::replace(rootS.begin(), rootS.end(), '/', '\\'); // replace all 'x' to 'y'
	root = rootS;

	return root;
}

boost::filesystem::path Mover::createExportDirectory(const boost::filesystem::path& path ) {
	boost::filesystem::path createDirectory;
	createDirectory /= exportDirectory;
	createDirectory /= path;

	return createDirectory.parent_path();
}

} /* namespace Copy */
