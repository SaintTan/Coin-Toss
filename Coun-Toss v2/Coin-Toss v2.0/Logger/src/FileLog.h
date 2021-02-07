#pragma once
#include "MainLog.h"
#include <ostream>
#include <string>

namespace Logger{
	class FileLog : public MainLog {
	private:
		std::ostream& targetFile;
	public:
		FileLog(std::ostream& targetFile);
		void LogMessage(const std::string& message, MessageLevel);
	};
}


