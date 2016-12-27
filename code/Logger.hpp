/*
 * Logger.hpp
 *
 *  Created on: 14 Nov 2016
 *      Author: Nico
 */

#ifndef LOGGER_SRC_LOGGER_HPP_
#define LOGGER_SRC_LOGGER_HPP_

#include "LogToFile.hpp"
#include "Queue.hpp"
#include "AppTimer.hpp"

#include "boost/filesystem.hpp"

namespace Logger
{
class Logger
{
public:
	virtual ~Logger();

	/**
	 * Static function that returns the instance of the logger
	 * @return The instance of the logger
	 */
	static Logger& getLogger();
	/**
	 * Function that writes the message to the log. Will take the first string out of the queue
	 */
	void writeToLogOutput();
	/**
	 * Function that writes the information to a queue. The queue will then proces the message to the logger with the writeToLogOutput function.
	 * @param logMessage String that contains the information that has to be logged
	 * @param logTime Boolean that tells to log the time or not.
	 */
	void log(const std::string& logMessage, bool time = false);
	/**
	 * @brief Function for logging an integer value
	 * @param logMessage An integer value that needs to be logged
	 * @param logTime An bool that tells if the time needs to be logged
	 */
	void log(const unsigned long logMessage, bool time = false);
	void log(const boost::filesystem::path& logMessage, bool time = false);
	const bool isErrorLogDone() const;
	/**
	 * @brief Function that returns a boolean judging if the logger is ready.
	 * @return True if the logger is done logging all the data.
	 */
	const bool isDone() const;
private:
	/**
	 * Private constructor so it can only be called by the logger itself
	 * @param aLogOutput Output type of the logger.
	 */
	Logger();
	Queue<std::string> queue;
	Queue<std::string> errorQueue;
	LogToFile output;
	//GETTERS, SETTERS and OPERATORS
	const Logger& operator=(const Logger& aLogger);
};
} /* namespace Logger */

#endif /* LOGGER_SRC_LOGGER_HPP_ */
