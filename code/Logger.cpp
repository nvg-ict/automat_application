/*
 * Logger.cpp
 *
 *  Created on: 14 Nov 2016
 *      Author: Nico
 */

#include "Logger.hpp"
#include "LogToFile.hpp"

#include <iostream>
#include <thread>

namespace Logger
{
Logger::Logger() :
		output(LogToFile("output"))
{
	output.connect();
	//std::thread t(&Logger::writeToLogOutput, this);
	//t.detach();
}

Logger::~Logger()
{
	output.disconnect();
}

const Logger& Logger::operator=(const Logger& aLogger)
{
	return *this;
}

void Logger::log(const std::string& logMessage)
{
	queue.enqueue(logMessage);
}

void Logger::log(const unsigned long logMessage)
{
	queue.enqueue(std::to_string(logMessage));
}

void Logger::log(const boost::filesystem::path& logMessage)
{
	queue.enqueue(logMessage.string());
}

Logger& Logger::getLogger()
{
	static Logger theLogger;
	return theLogger;
}

void Logger::writeToLogOutput()
{
	while (!isDone())
	{
		output.log(queue.dequeue());
	}
}

const bool Logger::isDone() const
{
	return queue.getQueueSize() == 0;
}
} /* namespace Logger */
