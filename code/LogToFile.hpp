/*
 * LogToFile.hpp
 *
 *  Created on: 14 Nov 2016
 *      Author: Nico
 */

#ifndef LOGGER_SRC_LOGTOFILE_HPP_
#define LOGGER_SRC_LOGTOFILE_HPP_

#include <string>
#include <fstream>

namespace Logger
{
class LogToFile
{
public:
	LogToFile(const std::string& aFileName);
	LogToFile(const LogToFile& l);
	virtual ~LogToFile();
	/**
	 * Function to connect the logger (In this case it creates a file and opens it for writing.)
	 */
	/*virtual*/
	void connect();
	/**
	 * Function to log the message to the logger. (In this case the string gets written in the file).
	 * @param aMessage A string containing the information that has to be logged
	 */
	/*virtual*/
	void log(const std::string& aMessage);
	/**
	 * Function to disconnect the logger (In this case it closes the file.)
	 */
	/*virtual*/
	void disconnect();

	std::string fileName;
	std::ofstream file;
};
} /* namespace Logger */

#endif /* LOGGER_SRC_LOGTOFILE_HPP_ */
