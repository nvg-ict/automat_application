/*
 * MainApp.cpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#include "MainApp.hpp"
#include <iostream>

namespace Application
{

MainApp::MainApp(boost::filesystem::path anExport) :
		c(), m(anExport)
{
}

MainApp::~MainApp()
{
}

void MainApp::runModFolder()
{
	matFiles = c.iterateDirectories();

	std::cout<<"Size: "<<matFiles.size()<<std::endl;

	iterateMatFile();
}

void MainApp::iterateMatFile()
{
	std::set<boost::filesystem::path>::iterator it;
	for (it = matFiles.begin(); it != matFiles.end(); ) {
	    if (m.copyFile(*it)) {
	        it = matFiles.erase(it);
	    }
	    else {
	        ++it;
	    }
	}
	std::cout<<"Size of matfiles: "<<matFiles.size()<<std::endl;
}



} /* namespace Application */
