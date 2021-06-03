#pragma once
#include <string>

namespace Logger {
	enum class MessageLevel {
		Error, Warning, Message, Trade
	};

	class MainLog {
	public:
		virtual void LogMessage(const std::string& message, MessageLevel level) = 0;
	};
}

