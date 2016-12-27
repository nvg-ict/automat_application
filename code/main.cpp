/*
 * main.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include "Collector.hpp"
#include "Logger.hpp"
#include "MainApp.hpp"
#include "AppTimer.hpp"

#include <iostream>               // for std::cout
#include <regex>
#include <string>
#include <set>
#include "boost/filesystem.hpp"


#include <chrono>
#include <thread>


int main(int argc, char **argv)
{
	//This must be the first function the programm calls
	Time::AppTimer::getTimer().init();

	try {
		boost::filesystem::path exportDirectory;
		   std::cout << "Have " << argc << " arguments:" << std::endl;
		    for (int i = 0; i < argc; ++i) {
		        std::cout << argv[i] << std::endl;
		    }
		if(argc==2)
		{
		exportDirectory = argv[1];
		}
		else
		{
			std::cout<<"Export directory for the application is missing. Please specify the path: "<<std::endl;
			std::cin >> exportDirectory;
		}
		std::cout << "Program has started" << std::endl;
		//Input::Collector c;
		//c.iterateDirectories();
		Application::MainApp m(exportDirectory);
		m.runModFolder();


		Logger::Logger::getLogger().writeToLogOutput();
		return 0;
	} catch (std::exception& e) {
		std::cout <<e.what() << std::endl;
	}

}


/*
#include <iostream>
#include "boost/filesystem.hpp"
namespace fs = boost::filesystem;
int main() {
    fs::path p1 = "C:";
    p1 /= "Users"; // does not insert a separator
                   // "C:Users" is a relative path in Windows
                   // adding directory separator would turn it to an absolute path
    std::cout << "\"C:\" / \"Users\" == " << p1 << '\n';
    p1 /= "batman"; // inserts fs::path::preferred_separator, '\' on Windows
    std::cout << "\"C:\" / \"Users\" / \"batman\" == " << p1 << '\n';
}
*/

