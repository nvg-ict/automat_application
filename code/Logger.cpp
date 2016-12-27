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

void Logger::log(const std::string& logMessage, bool time/*=false*/)
{
	if (time)
		errorQueue.enqueue(Time::AppTimer::getTimer().getTime() + logMessage);
	else
		queue.enqueue(logMessage);
}

void Logger::log(const unsigned long logMessage, bool time/*=false*/)
{
	if (time)
		errorQueue.enqueue(Time::AppTimer::getTimer().getTime() + std::to_string(logMessage));
	else
		queue.enqueue(std::to_string(logMessage));
}

void Logger::log(const boost::filesystem::path& logMessage, bool time/*=false*/)
{
	if (time)
		errorQueue.enqueue(Time::AppTimer::getTimer().getTime() + logMessage.string());
	else
		queue.enqueue(logMessage.string());
}

Logger& Logger::getLogger()
{
	static Logger theLogger;
	return theLogger;
}

void Logger::writeToLogOutput()
{
	if (!errorQueue.empty())
	{
		output.log("The following errors occured: ");
		while (!isErrorLogDone()) output.log(errorQueue.dequeue());
		output.log("\n");
	}
	while (!isDone()) output.log(queue.dequeue());
}

const bool Logger::isErrorLogDone() const
{
	return errorQueue.getQueueSize() == 0;
}

const bool Logger::isDone() const
{
	return queue.getQueueSize() == 0;
}
} /* namespace Logger */
