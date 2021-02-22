#include "ConsoleLog.h"
#include <iostream>

static void checkMessage(Logger::MessageLevel);

void Logger::ConsoleLog::LogMessage (const std::string& message, Logger::MessageLevel level){
	checkMessage(level);
	std::cout << message << std::endl;
}

static void checkMessage(Logger::MessageLevel level) {
	switch (level) {
	case (Logger::MessageLevel::Error) :
		std::cout << "[Error] : ";
		break;
	case (Logger::MessageLevel::Warning) : 
		std::cout << "[Warning] : ";
		break;
	case (Logger::MessageLevel::Message):
		std::cout << "[Message] : ";
		break;
	case (Logger::MessageLevel :: Trade):
		std::cout << "[Trade] : ";
		break;
	}
}