/*
 * AppTimer.cpp
 *
 *  Created on: 27 Dec 2016
 *      Author: Nico
 */

#include "AppTimer.hpp"

#include <iostream>

namespace Time
{

AppTimer::AppTimer()
:start(boost::posix_time::microsec_clock::local_time())
{
}

AppTimer::~AppTimer()
{
	// TODO Auto-generated destructor stub
}

AppTimer& AppTimer::getTimer()
{
	static AppTimer a;
	return a;
}

void AppTimer::init()
{
	initialised = true;
}

std::string AppTimer::timeNotation(unsigned long time)
{
	std::string a = "0.000";
	if(time < 9999) {
		std::string::iterator it = a.end();
		--it;
		*it = (48+time%10);
		--it;
		*it = (48+(time/10)%10);
		--it;
		*it = (48+(time/100)%10);
		--it;
		--it;
		*it = (48+(time/1000)%10);
	}
	return a;
}

const std::string AppTimer::getTime()
{
	if(initialised)
		{
		std::cout<<timeNotation(5255)<<std::endl;
		boost::posix_time::time_duration diff = boost::posix_time::microsec_clock::local_time() - start;
		return (std::to_string(diff.total_milliseconds()) + ": ");
		}
	else return "Time was not initialised: ";
}

} /* namespace Tim */
