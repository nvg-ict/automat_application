/*
 * LogToFile.cpp
 *
 *  Created on: 14 Nov 2016
 *      Author: Nico
 */

#include "LogToFile.hpp"

namespace Logger
{
LogToFile::LogToFile(const std::string& aFileName) :
		fileName(aFileName)
{
}

LogToFile::LogToFile(const LogToFile& l) :
		fileName(l.fileName)
{
}

LogToFile::~LogToFile()
{
}

void LogToFile::connect()
{
	file.open(fileName + ".txt", std::ios::out);
}

void LogToFile::log(const std::string& aMessage)
{
	if (file.is_open())
	{
		file << aMessage << std::endl;
	}
}

void LogToFile::disconnect()
{
	file.close();
}
} /* namespace Logger */
