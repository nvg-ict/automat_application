/*
 * AppTimer.hpp
 *
 *  Created on: 27 Dec 2016
 *      Author: Nico
 */

#ifndef CODE_APPTIMER_HPP_
#define CODE_APPTIMER_HPP_

#include <time.h>
#include <string>

#include "boost/date_time/posix_time/posix_time.hpp"

namespace Time
{

class AppTimer
{
public:
	virtual ~AppTimer();
	static AppTimer& getTimer();
	void init();
	const std::string getTime();
protected:
	AppTimer();
private:
	std::string timeNotation(unsigned long time);
	bool initialised = false;
	boost::posix_time::ptime start;
};

} /* namespace Tim */

#endif /* CODE_APPTIMER_HPP_ */
