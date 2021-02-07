#pragma once
#include "MainLog.h"
#include <string>

namespace Logger{
	class FileLog : public MainLog {
	private:
		std::string targetFile;
	public:
		FileLog(const std::string& targetFile);
		static void LogMessage(const std::string& message, MessageLevel);
	};
}


