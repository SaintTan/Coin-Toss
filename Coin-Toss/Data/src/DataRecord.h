#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

void write_toFile(std::wstring& source, const std::string& data);
static bool getCurrentLoc(const LPTSTR& buffer);