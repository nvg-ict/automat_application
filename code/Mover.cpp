/*
 * Mover.cpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#include "Mover.hpp"

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
void Mover::copyFile(boost::filesystem::path path)
{
	boost::filesystem::path root = boost::filesystem::current_path();
	boost::filesystem::path newLocation = boost::filesystem::current_path();
	boost::filesystem::path createDirectory;

	createDirectory /= exportDirectory;
	createDirectory		/= path;
	root /= path;
	newLocation /= exportDirectory;
	newLocation /= path;

	std::cout<<"Create path: "<<createDirectory.parent_path()<<std::endl;
	std::cout<<"Root path: "<<root<<std::endl;
	std::cout<<"New Location path: "<<newLocation<<std::endl;

	if (boost::filesystem::create_directories(createDirectory.parent_path()))
	{
		boost::filesystem::copy_file(root, newLocation, boost::filesystem::copy_option::overwrite_if_exists);
	}
	else {
		std::cout<<"Directory creating failed"<<std::endl;
	}
}
} /* namespace Copy */

/*
 fs::path dir ("/tmp");
 fs::path file ("foo.txt");
 fs::path full_path = dir / file;
 std::cout << full_path << std::endl;
 */
