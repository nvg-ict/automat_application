/*
 * Mover.cpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#include "Mover.hpp"
#include <algorithm>

#include <iostream>

namespace Copy
{

Mover::Mover(boost::filesystem::path anExport) :
		exportDirectory(anExport)
{
	// TODO Auto-generated constructor stub
}

Mover::~Mover()
{
	// TODO Auto-generated destructor stub
}

boost::filesystem::path Mover::destination(boost::filesystem::path path)
{
	boost::filesystem::path fullPath = exportDirectory;
	fullPath /= path;
	std::cout << "Destination: " << fullPath.string() << std::endl;
	return fullPath;
}

/*
 bool Mover::createNewDirectories(boost::filesystem::path path) {
 //boost::filesystem::path dir(path);
 if(boost::filesystem::create_directory(path))
 {
 std::cout<< "Directory Created: "<< path.string()<<std::endl;
 return true;
 }
 else {
 return false;
 }
 }
 */

bool Mover::checkIfMatPresent(boost::filesystem::path path) {
	std::cout<<path.string()<<std::endl;
	return boost::filesystem::exists(path);
}

void Mover::copyFile(boost::filesystem::path path)
{
	boost::filesystem::path root = boost::filesystem::current_path();
	boost::filesystem::path newLocation = boost::filesystem::current_path();
	boost::filesystem::path createDirectory;

	createDirectory /= exportDirectory;
	createDirectory /= path;
	root /= path;
	newLocation /= exportDirectory;
	newLocation /= path;

	std::cout << "Create path: " << createDirectory.parent_path() << std::endl;
	std::cout << "Root path: " << root << std::endl;
	std::cout << "New Location path: " << newLocation << std::endl;

	std::string rootS = root.string();
	std::string newLocationS = newLocation.string();
	std::replace(rootS.begin(), rootS.end(), '/', '\\'); // replace all 'x' to 'y'
	std::replace(newLocationS.begin(), newLocationS.end(), '/', '\\'); // replace all 'x' to 'y'

	if(checkIfMatPresent(rootS)) {


	boost::filesystem::create_directories(createDirectory.parent_path());
	try
	{
		//boost::system::error_code error;
		boost::filesystem::copy_file(rootS, newLocationS, boost::filesystem::copy_option::overwrite_if_exists);
	} catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cout << ex.path1() << std::endl;
		std::cout << "123: " << ex.what() << '\n';
	}
	}
	else {
		std::cout<<"MAT not present"<<std::endl;
	}
}

} /* namespace Copy */

/*
 fs::path dir ("/tmp");
 fs::path file ("foo.txt");
 fs::path full_path = dir / file;
 std::cout << full_path << std::endl;
 */
