#pragma once
#include "MainLog.h"
#include <string>

namespace Logger {
	class ConsoleLog : public MainLog {
	public:
		static void LogMessage(const std::string&, MessageLevel);
	};
}


