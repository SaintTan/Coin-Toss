#pragma once
#include "MainLog.h"
#include <fstream>

namespace Logger{
	class FileLog : public MainLog {
	private:
		std::ofstream targetFile;
	public:
		FileLog(const std::string&, const std::string&);
		FileLog(const std::string&);
		void LogMessage(const std::string& message, MessageLevel);
	
	};
}


