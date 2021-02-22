#pragma once
#include "MainLog.h"
#include <fstream>

namespace Logger{
	class FileLog : public MainLog {
	private:
		std::ofstream targetFile;
	public:
		FileLog(const std::string& fileLoc, const std::string& fileName);
		FileLog(const std::string& fileLoc);
		void LogMessage(const std::string& message, MessageLevel level);
	
	};
}


