#pragma once
#include "ConsoleLog.h"
#include <string>

int main() {
	Logger::ConsoleLog::LogMessage("wowzers", Logger::MessageLevel::Message);
}