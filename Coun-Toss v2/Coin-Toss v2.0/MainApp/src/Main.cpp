#pragma once
#include "ConsoleLog.h"
#include "DataManager.h"
#include "FileLog.h"
#include <string>

int main() {
	Data::DataManager dataManager(Data::FileType::RealTime, "hello.com");
}