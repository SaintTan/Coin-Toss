#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

static void getFilesLoc(const std::vector<std::wstring>&);
static int readInLocFilesNum(const std::wstring&);
static void readInLocFilesEntry(const std::wstring&, std::vector<std::wstring>&);
static int getDataNum(const std::wstring&);
static bool getCurrentLoc(const LPTSTR&);