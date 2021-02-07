#pragma once
#include "ConsoleLog.h"
#include "FileLog.h"
#include <fstream>
#include <string>

int main() {
	Logger::ConsoleLog::LogMessage("wowzers", Logger::MessageLevel::Message);
	Logger::FileLog Logtemp("test.txt");
	Logtemp.LogMessage("man", Logger::MessageLevel::Message);
}