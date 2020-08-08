#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

void write_toFile(std::wstring&, const std::string& ); //source, data : writes data to source
static bool getCurrentLoc(const LPTSTR&); //buffer: returns the current directory of file