/*
 * MainApp.hpp
 *
 *  Created on: 26 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_MAINAPP_HPP_
#define CODE_MAINAPP_HPP_

#include "Collector.hpp"
#include "Mover.hpp"

#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

namespace Application
{
class MainApp
{
public:
	MainApp(boost::filesystem::path anExport);
	virtual ~MainApp();
	void runModFolder();
private:
	Input::Collector c;
	Copy::Mover m;
	std::set<boost::filesystem::path> matFiles;
};

} /* namespace Application */

#endif /* CODE_MAINAPP_HPP_ */
