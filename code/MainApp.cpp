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
	// TODO Auto-generated constructor stub

}

MainApp::~MainApp()
{
	// TODO Auto-generated destructor stub
}

void MainApp::runModFolder()
{
	matFiles = c.iterateDirectories();

	std::cout<<"Size: "<<matFiles.size()<<std::endl;

	for(boost::filesystem::path p :matFiles)
	{
		m.copyFile(p);
	}
}



} /* namespace Application */
