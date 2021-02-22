#include "FileLog.h"
#include "ConsoleLog.h"

static std::string checkLevel(Logger::MessageLevel);

Logger::FileLog::FileLog(const std::string& fileLoc, const std::string& fileName):targetFile(fileLoc+fileName){}

Logger::FileLog::FileLog(const std::string& fileName) : targetFile(fileName) {}

void Logger::FileLog::LogMessage(const std::string& message, Logger::MessageLevel level) {
	std::string mainMessage =checkLevel(level) + message + "\n";
	targetFile.write(mainMessage.c_str(), mainMessage.size());
}

static std::string checkLevel(Logger::MessageLevel level) {
	switch (level) {
	case (Logger::MessageLevel::Error):
		return "[Error] : ";
	case (Logger::MessageLevel::Warning):
		return "[Warning] : ";
	case (Logger::MessageLevel::Message):
		return "[Message] : ";
	case (Logger::MessageLevel::Trade):
		return "[Trade] : ";
	}
	return "";
}

